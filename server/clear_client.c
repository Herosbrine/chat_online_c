/*
** GREGOIRE, OUNIS PROJECT, 2019
** undefined
** File description:
** server.c
*/

#include "server.h"
#include "client.h"
#include "my.h"

void clear_clients(client_t *clients, int actual)
{
    int i = 0;

    for (; i < actual; i++)
        close(clients[i].sock);
}