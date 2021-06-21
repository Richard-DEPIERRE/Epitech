/*
** EPITECH PROJECT, 2021
** ex04
** File description:
** add
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "string.h"

void join_c(string_t *this, char delim, const char * const * tab)
{
    char *str = malloc(sizeof(char) * 2);
    str[0] = delim;
    str[1] = '\0';
    assign_c(this, tab[0]);
    append_c(this, str);
    for (int i = 1; tab[i]; i++) {
        append_c(this, tab[i]);
        append_c(this, str);
    }
    this->str[strlen(this->str) - 1] = '\0';
    free(str);
}

void join_s(string_t *this, char delim, const string_t * const * tab)
{
    char *str = malloc(sizeof(char) * 2);
    str[0] = delim;
    str[1] = '\0';
    assign_s(this, tab[0]);
    append_c(this, str);
    for (int i = 1; tab[i]; i++) {
        append_s(this, tab[i]);
        append_c(this, str);
    }
    this->str[strlen(this->str) - 1] = '\0';
    free(str);
}