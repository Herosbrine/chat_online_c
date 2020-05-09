/*
** GREGOIRE, OUNIS, PROJECT, 2019
** undefined
** File description:
** my_socket.c
*/

#include "server.h"
#include "client.h"
#include "my.h"

int client_app(char *adresse_ip, char *pseudo)
{
//<-------creation du socket--------->
    int sock = init_connection(adresse_ip);
    char *buffer = NULL;
    fd_set rdfs;
    size_t sizeb = 1000;

    if (write_server(&sock, pseudo) == 84)
        return (84);
    buffer = malloc(sizeof(char) * BUFF_SIZE);
    while (1) {
        FD_ZERO(&rdfs);
        //<---ajouter SETDIN_FILENO------>
        FD_SET(STDIN_FILENO, &rdfs);
        //<---ajouter le socket----->
        FD_SET(sock, &rdfs);
        //<---examine le file descriptor mit en place a qui les adresse sont passee---->
        if (select(sock + 1, &rdfs, NULL, NULL, NULL) == -1) {
            perror("select()");
            return (84);
        }
        //<----appartient a la fct select----->
        //<------si il y a une quelque chose d'entree avec le clavier---->
        if (FD_ISSET(STDIN_FILENO, &rdfs)) {
            if (getline(&buffer, &sizeb, stdin) == -1)
                return (84);
            for (int i = 0; buffer[i] != '\0'; i++) {
                if (buffer[i] == '\n')
                    buffer[i] = '\0';
            }
            write_server(&sock, buffer);
        }
        else if (FD_ISSET(sock, &rdfs)) {
            int n = read_server(sock, buffer);
            //<------si le server est down---->
            if (n == 0) {
                my_printf("server disconnected !\n");
                break;
            }
            puts(buffer);
        }
    }
    end_connection(sock);
    //COTE SERVEUR//
//<------Création de l'interface, bind lie un socket avec une structure sockaddr-------->
    //bind(int sockfd, struct sockaddr * my_addrs, socklen_t addrlen);

//<--------Ecoute et connecion des clients : listen, fonction qui permet de definir la taille de la file de connexions en attente pour votre socket s------->
    //listen(int s, int backlog);

//<---------Cette fonction accept la connexion d'un socket sur le socket sock. Le socket aura ete prealablement lie avec un port avec la fonction bind()
//L'agurment adresse sera remplie avec les informations du client qui s'est connecté.
//cette fonction retourne une nouveau socket, qui devra être utilisé pour communiquer avec le client.----------->
    //accept(int sockfd, struct sockaddr *addresse, socklen_t *longueur);




    //COTE CLIENT//
// <---- cette fonction connecte ta socket a l'adresse specifier dans la structure sockaddr------>
    //if (connect(1, const struct sockaddr, socklen_t len) == -1)
    //    return (84);

//<--------cette fonction envoie sur le socket s , les données pointee par msg, pour une taille de len octets---------->
    //send(int s, "saluuut frerot", size_t len, int flags)

//<--------Elle recoit sur le socket s, les données qu'elle stockera à l'endroit pointé par buf, pour une taille max de len octets.-------->
    //recv(int s, void *buf, int len, unsigned int flags);
    return (0);
}