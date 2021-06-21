/*
** EPITECH PROJECT, 2019
** get_str
** File description:
** get string from int
*/

#include <stdlib.h>

char *my_revstr(char *str);

char *get_str(int nb)
{
    char *dest;
    int count = 0;
    int nb2 = nb;
    int i = 0;

    while (nb2 > 0) {
        nb2 /= 10;
        count += 1;
    }
    dest = malloc(sizeof(char) * (count + 1));
    while (nb > 0) {
        nb2 = nb;
        nb2 %= 10;
        dest[i] = nb2 + '0';
        nb /= 10;
        i++;
    }
    dest[i] = '\0';
    dest = my_revstr(dest);
    return (dest);
}
