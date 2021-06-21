/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** my str duplicate
*/

#include <stdlib.h>

char *my_strdup(char const *src)
{
    char *dest;
    int i = 0;
    int size = 0;

    while (src[size] != '\0') {
        size++;
    }
    dest = malloc(size * sizeof(char));
    for (; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return (dest);
}
