/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** my str cat
*/

#include "stdlib.h"

int my_strlen4(char const *str)
{
    int count = 0;

    while (str[count] != '\0') {
        count++;
    }
    return (count);
}

char *my_strcat(char *dest, char *src)
{
    int count = 0;
    int i = 0;
    char *res;

    count = my_strlen4(dest) ;
    res = malloc(sizeof(char) * (count + my_strlen4(src) + 1));
    while (dest[i] != '\0') {
        res[i] = dest[i];
        i += 1;
    }
    for (int j = 0; src[j]; j += 1) {
        res[i] = src[j];
        i += 1;
    }
    res[i] = '\0';
    return (res);
}
