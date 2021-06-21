/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** str_to_word_array.c
*/

#include "../include/my.h"

int count_c(char *str, char c)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == c)
            count += 1;
    }
    return (count);
}

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}

int count_line(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != ':' && str[i] != '\0'; i += 1)
        count += 1;
    return (count);
}

char *my_strndup(char *str, int a)
{
    char *dest = malloc(sizeof(char) * 4096);
    int i = 0;

    while (str[i] != ':' && i < a) {
        dest[i] = str[i];
        i += 1;
    }
    dest[a] = '\0';
    return (dest);
}

char **str_to_word_array(char *str)
{
    char **tableau = malloc(sizeof(char *) * 4096);
    int i = 0;

    for (int j = 0; j < my_strlen(str); j += 1) {
        tableau[i] = my_strndup(str + j, count_line(str + j));
        i += 1;
        j += count_line(str + j);
    }
    tableau[i] = NULL;
    return (tableau);
}