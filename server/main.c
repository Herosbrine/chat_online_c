/*
** GREGOIRE, OUNIS PROJECT, 2019
** undefined
** File description:
** server.c
*/

#include "server.h"
#include "client.h"
#include "my.h"

int main(void)
{
    verify();
    server_app();
    verify_end();
    return (0);
}