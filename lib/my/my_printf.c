/*
** EPITECH PROJECT, 2019
** undefined
** File description:
** my_printf.c
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my.h"

int my_printf(char const * format, ...)
{
    va_list(paramsinfos);
    va_start(paramsinfos, format);

    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++;
            if (my_printf2(&i, paramsinfos, format) == 1)
                return (0);
        }
        else {
            my_putchar(format[i]);
        }
    }
    return (0);
}