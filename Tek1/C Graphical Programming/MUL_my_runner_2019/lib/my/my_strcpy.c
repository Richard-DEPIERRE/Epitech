/*
** EPITECH PROJECT, 2019
** my_strcpy
** File description:
** my_strcpy
*/

#include "../../include/my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    dest = malloc(sizeof(char) * my_strlen(src) + 1);
    for (i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return (dest);
}
