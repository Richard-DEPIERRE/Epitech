/*
** EPITECH PROJECT, 2019
** funct
** File description:
** all_functions_needed
*/

#include "my_runner.h"

char *int_to_str(int nb)
{
    char *str = malloc(sizeof(char) * 2);

    str[0] = nb + 48;
    str[1] = '\0';
    return (str);
}

void my_putnbr2(int *tmp, char *str, int *len, int *nb)
{
    int i = 0;

    if (*tmp < 0)
        *tmp *= (-1);
    while (i < *len) {
        str[i] = (*tmp % 10) + 48;
        *tmp /= 10;
        i += 1;
    }
    if (*nb < 0) {
        str[i] = '-';
        i += 1;
    }
    str[i] = '\0';
}

char *my_putnbr(int nb)
{
    char *str;
    int tmp = nb;
    int len = 0;

    while (tmp != 0) {
        len += 1;
        tmp /= 10;
    }
    str = malloc(sizeof(char) * (len + 2));
    tmp = nb;
    my_putnbr2(&tmp, str, &len, &nb);
    my_revstr(str);
    return (str);
}