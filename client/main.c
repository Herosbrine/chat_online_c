/*
** GREGOIRE, OUNIS, 2019
** undefined
** File description:
** main.c
*/

#include "server.h"
#include "client.h"
#include "my.h"

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