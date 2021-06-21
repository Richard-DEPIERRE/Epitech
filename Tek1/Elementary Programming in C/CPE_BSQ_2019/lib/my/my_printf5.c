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

void check_length_int(char *str, int i, int nb)
{
    char *nb2 = malloc(sizeof(nb2));
    for (int j = 0; str[i] >= '0' && str[i] <= '9' ; j += 1) {
        nb2[j] = str[i];
        i += 1;
    }
    int count = my_getnbr(nb2);
    for (; nb != 0; count -= 1)
        nb /= 10;
    if (count > 0)
        for (; count > 0; count -= 1)
            my_putchar(' ');
}

void check_length_int2(char *str, int i, int nb)
{
    char *nb2 = malloc(sizeof(nb2));
    for (int j = 0; str[i] >= '0' && str[i] <= '9' ; j += 1) {
        nb2[j] = str[i];
        i += 1;
    }
    int count = my_getnbr(nb2);
    for (; nb != 0; count -= 1)
        nb /= 10;
    if (count > 0)
        for (; count > 0; count -= 1)
            my_putchar('0');
}

void check_length_str(char *str, int i, int nb)
{
    char *nb2 = malloc(sizeof(nb2));
    for (int j = 0; str[i] >= '0' && str[i] <= '9' ; j += 1) {
        nb2[j] = str[i];
        i += 1;
    }
    int count = my_getnbr(nb2);
    for (; nb != 0; count -= 1)
        nb -= 1;
    if (count > 0)
        for (; count > 0; count -= 1)
            my_putchar(' ');
}

void check_length_str2(char *str, int i, int nb)
{
    char *nb2 = malloc(sizeof(nb2));
    for (int j = 0; str[i] >= '0' && str[i] <= '9' ; j += 1) {
        nb2[j] = str[i];
        i += 1;
    }
    int count = my_getnbr(nb2);
    for (; nb != 0; count -= 1)
        nb -= 1;
    if (count > 0)
        for (; count > 0; count -= 1)
            my_putchar('0');
}