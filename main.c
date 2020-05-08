/*
** GREGOIRE, OUNIS, 2019
** undefined
** File description:
** main.c
*/

#include "chat_online.h"
#include "my.h"

int main(void)
{
    data_t socket;

    my_printf("<--------------PROJECT REALISER PAR OUNIS ET GREGOIRE-------------->\n");
    if (my_socket(&socket) == 84)
        return (84);
    return (0);
}