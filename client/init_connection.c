/*
** GREGOIRE, OUNIS, PROJECT, 2019
** undefined
** File description:
** my_socket.c
*/

#include "server.h"
#include "client.h"
#include "my.h"

int init_connection(char *adresse_ip)
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    SOCKADDR_IN sin = { 0 };
    struct hostent *hostinfo;
    if (sock == INVALID_SOCKET) {
        perror("socket()");
        exit (84);
    }
    hostinfo = gethostbyname(adresse_ip);
    if (hostinfo == NULL) {
        my_printf("Unknow host %s.\n", adresse_ip);
        exit (84);
    }
    sin.sin_addr = *(IN_ADDR *) hostinfo->h_addr;
    //<------convert unsigned int en host byte order
    sin.sin_port = htons(PORT);
    sin.sin_family = AF_INET;
    if (connect(sock, (SOCKADDR *) &sin, sizeof(SOCKADDR)) == SOCKET_ERROR) {
        perror("connect()");
        exit (84);
    }
    return (sock);
}