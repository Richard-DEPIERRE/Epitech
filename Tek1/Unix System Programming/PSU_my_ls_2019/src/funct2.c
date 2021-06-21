/*
** EPITECH PROJECT, 2020
** funct2
** File description:
** file for generic functions
*/

#include "my_ls.h"

int get_size(char *str)
{
    DIR *dir;
    struct dirent *sd;
    int count = 0;

    dir = opendir(str);
    while ((sd = readdir(dir)) != NULL) {
        if (sd->d_name[0] != '.')
            count += 1;
    }
    return (count);
}

int check2(char c, char c2, int *count)
{
    if (c == c2 && *count == 0) {
        *count = 1;
        return (0);
    } else if (c == c2 && *count == 1)
        return (84);
    return (0);
}

int check3(char c)
{
    int count = 0;

    if (c == 'R')
        count += 1;
    if (c == 'l')
        count += 1;
    if (c == 'd')
        count += 1;
    if (c == 't')
        count += 1;
    if (c == 'r')
        count += 1;
    if (count == 0)
        return (84);
    else
        return (0);
}

char *my_strcpy2(char *src)
{
    return src;
}

int operator_is_present(char **str, char c)
{
    for (int i = 0; str[i]; i += 1)
        if (str[i][0] == c)
            return (1);
    return (0);
}