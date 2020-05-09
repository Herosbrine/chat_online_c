/*
** GREGOIRE, OUNIS, PROJECT, 2019
** undefined
** File description:
** my_socket.c
*/

#include "server.h"
#include "client.h"
#include "my.h"

int read_server(int sock, char *buffer)
{
    int n = 0;

    if ((n = recv(sock, buffer, BUFF_SIZE - 1, 0)) < 0) {
        perror("recv()");
        exit (84);
    }
    buffer[n] = '\0';
    return (n);
}