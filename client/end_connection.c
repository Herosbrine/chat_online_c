/*
** GREGOIRE, OUNIS, PROJECT, 2019
** undefined
** File description:
** my_socket.c
*/

#include "server.h"
#include "client.h"
#include "my.h"

void end_connection(int sock)
{
    close(sock);
}