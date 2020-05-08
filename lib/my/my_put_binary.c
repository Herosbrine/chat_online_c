/*
** EPITECH PROJECT, 2019
** undefined
** File description:
** my_put_binary.c
*/
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my.h"

int my_put_binary(unsigned int nbr)
{
    unsigned int binaryNum[100];
    unsigned int i = 0;

    while (nbr > 0) {
        binaryNum[i] = nbr % 2;
        nbr = nbr / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
        my_putchar(binaryNum[j] + 48);
    return (0);
}