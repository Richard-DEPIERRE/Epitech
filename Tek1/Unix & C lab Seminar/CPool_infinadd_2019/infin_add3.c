/*
** EPITECH PROJECT, 2019
** infin_add3
** File description:
** third file for infin_add
*/

#include <stdlib.h>
#include <stdio.h>
#include "include/my.h"

char plus_little(char *plus, char *minus, int i, char *dest)
{
    char nb = 0;

    if (plus[i + 1] >= '0') {
        minus[i + 1] += 1;
        nb = ((plus[i] - '0') + 10) - (minus[i] - '0');
        return (nb + '0');
    }
    if (plus[i + 1] != '0') {
        nb = (minus[i] - '0') - (plus[i] - '0');
        //dest[i + 1] = '-';
        return(nb + '0');
    }
}

void add_them_together(char *plus, char *minus, char *dest, int len_long)
{
    int size_plus = 0;
    int size_minus = 0;
    int count = 0;

    size_plus = my_strlen(plus) - 1;
    size_minus = my_strlen(minus) - 1;
    for (int i = 0; i <= size_plus || i <= size_minus; i += 1) {
        if (plus[i] >= minus[i]) {
            dest[i] = (plus[i] - '0') - (minus[i] - '0');
            dest[i] = dest[i] + '0';
            count = 0;
        }
        if (plus[i] < minus[i]) {
            dest[i] = plus_little(plus, minus, i, dest);
        }
    }
    my_revstr(dest);
    my_putstr(dest);
}

void minus_plus(char *plus, char *minus)
{
    char *dest;
    int len_long = 0;

    if (my_strlen(plus) >= my_strlen(minus)) {
        len_long = my_strlen(plus);
        minus = add_zeros(minus, len_long);
    } else if (my_strlen(minus) > my_strlen(plus)) {
        len_long = my_strlen(minus);
        plus = add_zeros(plus, len_long);
    }
    dest = malloc(sizeof(*dest) * (len_long + 2));
    dest[len_long + 1] = '\0';
    plus = my_revstr(plus);
    minus = my_revstr(minus);
    add_them_together(plus, minus, dest, len_long);
}

void char_compare(char *nb1, char *nb2)
{
    int i = 0;
    int j = 1;

    for (; nb2[j] == nb1[i]; i++)
            j++;
        if (nb2[j] < nb1[i])
            minus_plus(nb2 + 1, nb1);
        if (nb2[1] > nb1[0]) {
            my_putchar('-');
            minus_plus(nb2 + 1, nb1);
        }
}

void infin_add_positive_negative(char *nb1, char *nb2)
{
    if (nb1[0] == '-' && my_strlen(nb2) != (my_strlen(nb1) - 1)) {
        if (my_strlen(nb2) > (my_strlen(nb1) - 1))
            minus_plus(nb2, nb1 + 1);
        if ((my_strlen(nb1) - 1) > my_strlen(nb2)) {
            my_putchar('-');
            minus_plus(nb1 + 1, nb2);
        }
    }
    if (nb2[0] == '-' && (my_strlen(nb2) - 1) != my_strlen(nb1)) {
        if (my_strlen(nb2) > (my_strlen(nb1) - 1))
            minus_plus(nb2, nb1 + 1);
        if ((my_strlen(nb1) - 1) > my_strlen(nb2)) {
            my_putchar('-');
            minus_plus(nb1 + 1, nb2);
        }
    }
    if (nb2[0] == '-' && (my_strlen(nb2) - 1) == my_strlen(nb1))
        char_compare(nb1, nb2);
    if (nb1[0] == '-' && my_strlen(nb2) == (my_strlen(nb1) - 1))
        char_compare(nb2, nb1);
}