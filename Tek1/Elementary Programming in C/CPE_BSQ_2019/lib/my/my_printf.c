/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** prints character based on what you give it
*/

#include "../../include/my_printf.h"

static funct_t flags[] = {
    {'o', print_0},
    {'x', print_0x},
    {'X', print_0X},
};

int check_funct2(char *str, int i)
{
    if (str[i] == '-')
        i += 1;
    while (str[i] >= '0' && str[i] <= '9')
        i += 1;
    return i;
}

int check_funct(char *str, int i, va_list ap)
{
    int check = 0;
    i = check_funct2(str, i);
    for (int j = 0; j < 11; j += 1){
        if (str[i] == funct[j].c) {
            funct[j].ptr(ap, str, i);
            check = 1;
        }
    }
    if (str[i + 1] == '#')
        i += 1;
    for (int j = 0; j < 3 && check == 0; j += 1) {
        if (str[i] == flags[j].c) {
            flags[j].ptr(ap, str, i);
            check = 1;
        }
    }
    if (check == 0) {
        my_putchar('%');
        my_putchar(str[i]);
    }
    return i;
}

void my_printf(char *str, ...)
{
    int i = 0;
    va_list ap;

    va_start(ap, str);
    for (i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == '%' && str[i + 1] != '%') {
            i = check_funct(str, i + 1, ap);
        } else if (str[i] == '%' && str[i + 1] == '%') {
            my_putchar('%');
            i = i + 1;
        } else {
            my_putchar(str[i]);
        }
    }
    va_end(ap);
}