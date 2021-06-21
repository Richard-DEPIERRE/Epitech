/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** prints character based on what you give it
*/

//#include "include/my_printf.h"

#include <stdio.h>
#include <stdarg.h>
#include "../../include/my.h"

void print_char(va_list ap, char *str, int i)
{
    my_putchar(va_arg(ap, int));
}

void print_str(va_list ap, char *str, int i)
{
    int count = 0;
    char *res = va_arg(ap, char *);
    for (; str[i] != '%'; i -= 1)
        count += 1;
    i += 1;
    if (count == 1)
        my_putstr(res);
    else if (str[i] != '0') {
        if (str[i] > '0' && str[i] <= '9') {
            check_length_str(str, i, my_strlen(res));
            my_putstr(res);
        } else if (str[i] == '-') {
            i += 1;
            my_putstr(res);
            check_length_str(str, i, my_strlen(res));
        }
    } else {
        i += 1;
        if (str[i] > '0' && str[i] <= '9') {
            check_length_str2(str, i, my_strlen(res));
            my_putstr(res);
        } else if (str[i] == '-') {
            i += 1;
            my_putstr(res);
            check_length_str2(str, i, my_strlen(res));
        }
    }
}

void print_pointer(va_list ap, char *str, int i)
{
    long long count = va_arg(ap, long long);
    my_putstr("0x");
    my_putnbr_base_long(i, "0123456789abcdef");
}

void print_0(va_list ap, char *str, int i)
{
    my_putchar('0');
    my_putnbr_base(va_arg(ap, int), "01234567");
}

