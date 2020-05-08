/*
** EPITECH PROJECT, 2019
** undefined
** File description:
** my_put_nbr.c
*/

#include "my.h"

int my_put_nbr2(unsigned int nbr)
{
    if (nbr >= 10) {
        my_put_nbr(nbr / 10);
        my_put_nbr(nbr % 10);
    }
    else {
        my_putchar(nbr + '0');
    }
    return (0);
}