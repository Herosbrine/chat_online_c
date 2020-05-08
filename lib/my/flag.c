/*
** EPITECH PROJECT, 2019
** undefined
** File description:
** flag.c
*/

#include <stdarg.h>
#include "my.h"

int my_flag(int i, va_list paramsinfos, char const * format, ...)
{
    if (format[i] == 's')
        my_putstr(va_arg(paramsinfos, const char *));
    if (format[i] == 'c')
        my_putchar(va_arg(paramsinfos, int));
    if (format[i] == 'd' || format[i] == 'i')
        my_put_nbr(va_arg(paramsinfos, int));
    if (format[i] == 'u')
        my_put_nbr2(va_arg(paramsinfos, unsigned int));
    if (format[i] == 'o')
        my_put_octal(va_arg(paramsinfos, unsigned int));
    if (format[i] == 'X')
        my_put_hexa(va_arg(paramsinfos, unsigned int));
    if (format[i] == 'x')
        my_put_hexa_min(va_arg(paramsinfos, unsigned int));
    if (format[i] == 'b')
        my_put_binary(va_arg(paramsinfos, unsigned int));
    return (0);
}