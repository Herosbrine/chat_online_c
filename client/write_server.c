/*
** GREGOIRE, OUNIS, PROJECT, 2019
** undefined
** File description:
** my_socket.c
*/

#include "server.h"
#include "client.h"
#include "my.h"

int write_server(int *sock, char *pseudo)
{
    if (send(*sock, pseudo, my_strlen(pseudo), 0) < 0) {
        perror("send()");
        return (84);
    }
    return (0);
}