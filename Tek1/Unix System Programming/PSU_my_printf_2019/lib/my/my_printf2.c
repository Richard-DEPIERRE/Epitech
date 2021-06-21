/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** prints character based on what you give it
*/

#include <stdio.h>
#include <stdarg.h>
#include "../../include/my.h"

void print_int(va_list ap, char *str, int i)
{
    int count = 0;
    int res = va_arg(ap, int);
    for (; str[i] != '%'; i -= 1)
        count += 1;
    i += 1;
    if (count == 1)
        my_putnbr(res);
    else if (str[i] != '0') {
        if (str[i] > '0' && str[i] <= '9') {
            check_length_int(str, i, res);
            my_putnbr(res);
        } else if (str[i] == '-') {
            i += 1;
            my_putnbr(res);
            check_length_int(str, i, res);
        }
    } else {
        i += 1;
        if (str[i] > '0' && str[i] <= '9') {
            check_length_int2(str, i, res);
            my_putnbr(res);
        } else if (str[i] == '-') {
            i += 1;
            my_putnbr(res);
            check_length_int2(str, i, res);
        }
    }
}

void print_unsigned_int(va_list ap, char *str, int i)
{
    i = va_arg(ap, int);
    if (i < 0)
        my_putnbr_unsigned(4294967296 + i);
    else
        my_putnbr_unsigned(i);
}

void print_octal(va_list ap, char *str, int i)
{
    my_putnbr_base(va_arg(ap, int), "01234567");
}

void print_hexa(va_list ap, char *str, int i)
{
    my_putnbr_base(va_arg(ap, int), "0123456789abcdef");
}

void print_Hexa(va_list ap, char *str, int i)
{
    my_putnbr_base(va_arg(ap, int), "0123456789ABCDEF");
}
