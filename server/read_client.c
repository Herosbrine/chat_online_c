/*
** GREGOIRE, OUNIS PROJECT, 2019
** undefined
** File description:
** server.c
*/

#include "server.h"
#include "client.h"
#include "my.h"

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