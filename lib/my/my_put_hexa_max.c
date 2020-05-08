/*
** EPITECH PROJECT, 2019
** undefined
** File description:
** my_put_Hexa.c
*/

#include "my.h"

int my_put_hexa(unsigned nbr)
{
    long quotient = 0;
    int i = 1, j, temp;
    char hexadecimalNumber[100];

    quotient = nbr;
    while (quotient != 0) {
        temp = quotient % 16;
        if ( temp < 10)
            temp = temp + 48;
        else
            temp = temp + 55;
        hexadecimalNumber[i++] = temp;
        quotient = quotient / 16;
    }
    for (j = i -1; j> 0; j--)
        my_putchar(hexadecimalNumber[j]);
    return (0);
}