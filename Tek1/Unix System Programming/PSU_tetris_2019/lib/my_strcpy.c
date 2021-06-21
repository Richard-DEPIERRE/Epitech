/*
** EPITECH PROJECT, 2020
** my_strcpy
** File description:
** copies a string in another
*/

#include "tetris.h"

char *my_strcpy(char *src, char *dest)
{
    char *desti = malloc(sizeof(char) * (my_strlength(src) + 1));
    desti[my_strlength(src)] = '\0';
    for (int i = 0; src[i]; i += 1)
        desti[i] = src[i];
    return (desti);
}