/*
** EPITECH PROJECT, 2020
** my_strlength
** File description:
** length of string
*/

#include "tetris.h"

int my_strlength(char *str)
{
    int a = 0;

    for (; str[a]; a++);
    return (a);
}