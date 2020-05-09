/*
** GREGOIRE, OUNIS, 2019
** undefined
** File description:
** main.c
*/

#include "server.h"
#include "client.h"
#include "my.h"

static void verify(void)
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

static void verify_end(void)
{
    #ifdef WIN32
    WSACleanup();
    #endif
}

int main(int ac, char **argv)
{
    if (ac < 3 || ac > 3) {
        my_printf("USAGE : %s [adresse_ip] [pseudo]\n", argv[0]);
        return (84);
    }
//<----pour la platforme WIN32---->
    verify();
    if (client_app(argv[1], argv[2]) == 84)
        return (84);
    verify_end();
    my_printf("<--------------PROJECT REALISER PAR OUNIS ET GREGOIRE-------------->\n");
    return (0);
}