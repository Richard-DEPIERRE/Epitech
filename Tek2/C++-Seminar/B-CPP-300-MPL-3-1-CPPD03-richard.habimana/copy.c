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

size_t copy(const string_t *this, char *s, size_t n, size_t pos)
{
    size_t a = 0;

    for (;(a == 0 || this->str[a - 1] != '\0') && a < n; a++)
        s[a] = this->str[a + pos];
    return (a);
}