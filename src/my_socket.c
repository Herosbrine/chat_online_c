/*
** GREGOIRE, OUNIS, PROJECT, 2019
** undefined
** File description:
** my_socket.c
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include "chat_online.h"
#include "my.h"

int my_socket(data_t *my_socket)
{
//<-------creation du socket--------->
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        perror("socket()");
        return (84);
    }

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