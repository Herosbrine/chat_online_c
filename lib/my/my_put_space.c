/*
** EPITECH PROJECT, 2019
** undefined
** File description:
** my_put_space.c
*/
#include "my.h"

int my_put_space(int i, char const *format)
{
    int x = 0;
    int n = 0;

    while (format[i] <= '9' && format[i] >= '0') {
        n = n * 10;
        n = n + format[i] - 48;
        i++;
    }
    while (n - 1 != x) {
        my_putchar(' ');
        x++;
    }
    return (0);
}