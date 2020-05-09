/*
** GREGOIRE, OUNIS PROJECT, 2019
** undefined
** File description:
** server.c
*/

#include "server.h"
#include "client.h"
#include "my.h"

static void verify(void)
{
    #ifdef  WIN32
    WSADATA wsa;
    int err = WSAStartup(MAKEWORD(2, 2), &wsa);
    if (err < 0) {
        my_printf("WSAStartup failed !");
        exit (84);
    }
    #endif
}

static void verify_end(void)
{
    #ifdef WIN32
    WSACleanup();
    #endif
}


int init_connection2(void)
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    SOCKADDR_IN sin = { 0 };
    if (sock == INVALID_SOCKET) {
        perror("socket()");
        exit (84);
    }
    sin.sin_addr.s_addr = htonl(INADDR_ANY);
    //<------convert unsigned int en host byte order
    sin.sin_port = htons(PORT);
    sin.sin_family = AF_INET;
    if (bind(sock, (SOCKADDR *) &sin, sizeof sin) == SOCKET_ERROR) {
        perror("bind()");
        exit (84);
    }
    //<----max file d'attente de client---->
    if (listen(sock, MAX_CLIENTS) == SOCKET_ERROR) {
        perror("listen()");
        exit (84);
    }
    return (sock);
}

void clear_clients(client_t *clients, int actual)
{
    int i = 0;

    for (; i < actual; i++)
        close(clients[i].sock);
}
//<-------enlever clients specifique------->
void remove_client(client_t *clients, int to_remove, int *actual)
{
    memmove(clients + to_remove, clients + to_remove + 1, (*actual - to_remove - 1) * sizeof(BUFF_SIZE));
    (*actual)--;
}

int read_client(int sock, char *buffer)
{
    int n = 0;

    if ((n = recv(sock, buffer, BUFF_SIZE - 1, 0)) < 0) {
        perror("recv()");
        //<---- si recv error alors on deconnect le client---->
        n = 0;
    }
    buffer[n] = '\0';
    return (n);
}

void write_client(int sock, char *buffer)
{
    if (send(sock, buffer, strlen(buffer), 0) < 0) {
        perror("send()");
        exit (84);
    }
}

void send_message_to_all_clients(client_t *clients, client_t *sender, int actual, const char *buffer, char from_server)
{
    int i = 0;
    char *message = NULL;
    message = malloc(sizeof(char) * BUFF_SIZE);
    message[0] = 0;
    for (; i < actual; i++) {
        //<----ON associe le message a son client----->
        if (sender->sock != clients[i].sock) {
            if (from_server == 0) {
                strncpy(message, sender->name, BUFF_SIZE - 1);
                strncat(message, " : ", sizeof message - strlen(message) - 1);
            }
            strncat(message, buffer, sizeof message - strlen(message) - 1);
            write_client(clients[i].sock, message);
        }
    }
}

int server_app(void)
{
    int sock = init_connection2();
    char *buffer = NULL;
    int i = 0;
    //<---l'index pour le tableau---->
    int actual = 0;
    int max = sock;
    int csock = 0;
    int c = 0;
    //<-----creation d'un tableau de client
    client_t clients[MAX_CLIENTS];
    fd_set rdfs;

    buffer = malloc(sizeof(char) * BUFF_SIZE);
    while (1) {
        //<----compte client----->
        FD_ZERO(&rdfs);
        FD_SET(STDIN_FILENO, &rdfs);
        //<---add the connection socket----->
        FD_SET(sock, &rdfs);
        //<----ajou de la socket pour chaque client----->
            i = 0;
            for (; i < actual; i++)
                FD_SET(clients[i].sock, &rdfs);
            if (select(max + 1, &rdfs, NULL, NULL, NULL) == -1) {
                perror("select()");
                exit (84);
            }
            if (FD_ISSET(STDIN_FILENO, &rdfs)) {
                //<-----arret du process quand on tappe sur le clavier---->
                break;
            }
            else if (FD_ISSET(sock, &rdfs)) {
                //<-----nouveau client---->
                SOCKADDR_IN csin = { 0 };
                unsigned int sinsize = sizeof csin;
                csock = accept(sock, (SOCKADDR *) &csin, &sinsize);
                if (csock == SOCKET_ERROR) {
                    perror("accept()");
                    continue;
                }
                //après la connection le client envoie sont nom------>
                if (read_client(csock, buffer) == -1) {
                    //<-----deconnecter------>
                    continue;
                }
                //<---------quelle est le maximum fd----->
                max = csock > max ? csock : max;
                FD_SET(csock, &rdfs);
                client_t c = { csock };
                strncpy(c.name, buffer, BUFF_SIZE - 1);
                clients[actual] = c;
                actual++;
            }
            else {
                i = 0;
                for (; i < actual; i++) {
                    //<----un cient parle----->
                    if (FD_ISSET(clients[i].sock, &rdfs)) {
                        client_t client = clients[i];
                        c = read_client(clients[i].sock, buffer);
                        if (c == 0) {
                            close(clients[i].sock);
                            remove_client(clients, i, &actual);
                            strncpy(buffer, client.name, BUFF_SIZE - 1);
                            strncat(buffer, "disconnected ! ", BUFF_SIZE - strlen(buffer) - 1);
                            send_message_to_all_clients(clients, &client, actual, buffer, 1);
                        }
                        else
                            send_message_to_all_clients(clients, &client, actual, buffer, 0);
                        break;
                    }
                }
            }
    }
    clear_clients(clients, actual);
    end_connection(sock);
    return (0);
}