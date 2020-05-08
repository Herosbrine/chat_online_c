/*
** EPITECH PROJECT, 2019
** my
** File description:
** my_printf2.c
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my.h"

int my_printf2(int *i, va_list paramsinfos, char const * format, ...)
{
    while (format[*i] == ' ') {
        (*i)++;
        if ((format[*i] != ' ' && format[*i] == 'd') || format[*i] == 'i')
            my_putchar(' ');
    }
    while (format[*i] == '%') {
        if (format[*i] != '%')
            my_putchar('%');
        while (format[*i] != '\0') {
            my_putchar(format[*i]);
            (*i)++;
        }
        return (1);
    }
    while (format[*i] >= '0' && format[*i] <= '9') {
        my_put_space(*i, format);
        (*i)++;
    }
    my_flag(*i, paramsinfos, format);
    return (0);
}