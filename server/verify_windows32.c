/*
** GREGOIRE, OUNIS PROJECT, 2019
** undefined
** File description:
** server.c
*/

#include "server.h"
#include "client.h"
#include "my.h"

void verify(void)
{
    #ifdef  WIN32
    WSADATA wsa;
    int err = WSAStartup(MAKEWORD(2, 2), &wsa);
    if (err < 0) {
        my_printf("WSAStartup failed !");
        exit (84);
    }
    #endif
}

void verify_end(void)
{
    #ifdef WIN32
    WSACleanup();
    #endif
}