/*
** EPITECH PROJECT, 2019
** infin_add2
** File description:
** second file for infin_add
*/

#include <stdlib.h>
#include <stdio.h>
#include "include/my.h"

char *add_zeros(char *nb, int size)
{
    char *dest;
    int size_nb = 0;

    size_nb = my_strlen(nb);
    dest = malloc(sizeof(char) * (size + 1));
    dest[my_strlen(dest)] = '\0';
    while (size >= 0) {
        size -= 1;
        size_nb -= 1;
        if (size_nb >= 0)
            dest[size] = nb[size_nb];
        if (size_nb < 0)
            dest[size] = '0';
    }
    return (dest);
}

int check_count(char *dest, char *nb1, char *nb2)
{
    int size_nb1 = 0;
    int size_nb2 = 0;
    int count = 0;
    int i = 0;

    size_nb1 = my_strlen(nb1) - 1;
    size_nb2 = my_strlen(nb2) - 1;
    for (i = 0; i <= size_nb1 || i <= size_nb2; i += 1) {
        dest[i] = (nb1[i] - '0') + (nb2[i] - '0') + count;
        count = dest[i] / 10;
        dest[i] = dest[i] % 10;
        dest[i] = dest[i] + '0';
    }
    if (count != 0)
        dest[i] = count + '0';
    dest = my_revstr(dest);
    my_putstr(dest);
}

void infin_add_positives(char *nb1, char *nb2)
{
    char *dest;
    int len_long = 0;

    if (my_strlen(nb1) >= my_strlen(nb2)) {
        len_long = my_strlen(nb1);
        nb2 = add_zeros(nb2, len_long);
    } else if (my_strlen(nb1) < my_strlen(nb2)) {
        len_long = my_strlen(nb2);
        nb1 = add_zeros(nb1, len_long);
    }
    dest = malloc(sizeof(char) * (len_long + 1));
    dest[len_long + 1] = '\0';
    nb1 = my_revstr(nb1);
    nb2 = my_revstr(nb2);
    check_count(dest, nb1, nb2);
}