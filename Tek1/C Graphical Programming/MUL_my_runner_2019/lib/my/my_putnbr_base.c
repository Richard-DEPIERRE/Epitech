/*
** EPITECH PROJECT, 2019
** my_putnbr_base
** File description:
** my put nbr for any base
*/

#include "../../include/my.h"

int my_putnbr_base(int nbr, char *base)
{
    int count = 0;
    char *str = malloc(sizeof(str));
    if (nbr < 0)
        nbr *= -1;
    for (int i = 0; nbr > 0; i += 1) {
        count = nbr % my_strlen(base);
        str[i] = base[count];
        nbr /= my_strlen(base);
    }
    my_revstr(str);
    my_putstr(str);
    free(str);
}