/*
** GREGOIRE, OUNIS PROJECT, 2019
** undefined
** File description:
** server.c
*/

#include "server.h"
#include "client.h"
#include "my.h"

void write_client(int sock, char *buffer)
{
    if (send(sock, buffer, strlen(buffer), 0) < 0) {
        perror("send()");
        exit (84);
    }
}