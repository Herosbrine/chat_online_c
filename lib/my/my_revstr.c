/*
** EPITECH PROJECT, 2019
** my_revstr.c
** File description:
** my_revstr.c
*/

#include "my.h"

char *my_revstr(char *str)
{
    int x = 0;
    char inverse;

    if (str == 0) {
        return (0);
    }
    x = my_strlen(str) - 1;
    if (x == 0) {
        return (str);
    }
    for (int a = 0; a <= x; a++) {
        inverse = str[a];
        str[a] = str[x];
        str[x] = inverse;
        x--;
    }
    return (str);
}