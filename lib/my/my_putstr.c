/*
** EPITECH PROJECT, 2019
** my_putstr.c
** File description:
** my_putstr.c
*/

#include "my.h"
#include <stdlib.h>

int my_putstr(char const *str)
{
    int i = 0;

    if (str == NULL)
        return (0);
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return (0);
}