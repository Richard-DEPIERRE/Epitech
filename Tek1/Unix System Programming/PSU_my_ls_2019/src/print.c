/*
** EPITECH PROJECT, 2020
** print
** File description:
** print functions file
*/

#include "my_ls.h"

void print_folder(char *str)
{
    int i = 0;
    for (; str[i]; i += 1);
    write(1, str, i);
}