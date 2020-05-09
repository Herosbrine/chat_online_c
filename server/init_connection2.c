/*
** GREGOIRE, OUNIS PROJECT, 2019
** undefined
** File description:
** server.c
*/

#include "server.h"
#include "client.h"
#include "my.h"

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