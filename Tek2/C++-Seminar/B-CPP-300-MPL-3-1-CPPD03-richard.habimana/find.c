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

int find_c(const string_t *this, const char *str, size_t pos)
{
    size_t size = strlen(str);
    for (; pos < strlen(this->str); pos++)
        if (strncmp(this->str + pos, str, size) == 0)
            return (pos);
    return (-1);
}

int find_s(const string_t *this, const string_t *str, size_t pos)
{
    return find_c(this, str->str, pos);
}