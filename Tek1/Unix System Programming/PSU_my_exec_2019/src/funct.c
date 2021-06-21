/*
** EPITECH PROJECT, 2020
** funct
** File description:
** files contain generic functions
*/

#include "minishell.h"

int my_strlen4(char const *str)
{
    int count = 0;

    while (str[count]) {
        count++;
    }
    return (count);
}

char *strcpy4(char *dest, char const *src)
{
    int i = 0;

    for (; src[i]; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return (dest);
}

char *my_revstr4(char *str)
{
    char dest[my_strlen4(str)];
    int count = 0;

    count = my_strlen4(str) - 1;
    strcpy4(dest, str);
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = dest[count];
        count--;
    }
    return (str);
}

void int_to_char2(int *tmp, char *str, int *len, int *nb)
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

char *int_to_char(int nb)
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
    int_to_char2(&tmp, str, &len, &nb);
    my_revstr4(str);
    return (str);
}