/*
** GREGOIRE, OUNIS PROJECT, 2019
** undefined
** File description:
** server.c
*/

#include "server.h"
#include "client.h"
#include "my.h"

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
                            send_message_to_all_clients(clients, client, actual, buffer, 1);
                        }
                        else
                            send_message_to_all_clients(clients, client, actual, buffer, 0);
                        break;
                    }
                }
            }
    }
    clear_clients(clients, actual);
    end_connection(sock);
    return (0);
}