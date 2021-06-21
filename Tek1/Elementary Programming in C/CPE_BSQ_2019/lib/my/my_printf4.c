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

void print_0x(va_list ap, char *str, int i)
{
    my_putstr("0x");
    my_putnbr_base(va_arg(ap, int), "0123456789abcdef");
}

void print_0X(va_list ap, char *str, int i)
{
    my_putstr("0X");
    my_putnbr_base(va_arg(ap, int), "0123456789ABCDEF");
}

void print_sign_of_nb(va_list ap, char *str, int i)
{
    int nb = va_arg(ap, int);
    if (nb < 0)
        my_putchar('-');
    if (nb >= 0)
        my_putchar(' ');
}

void print_binary(va_list ap, char *str, int i)
{
    my_putnbr_base(va_arg(ap, int), "01");
}

void print_str_mod(va_list ap, char *str, int i)
{
    my_putstr_mod(va_arg(ap, char *));
}
