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

void assign_c(string_t *this, const char *s)
{
    string_destroy(this);
    this->str = malloc(sizeof(char) * (strlen(s) + 1));
    for (size_t i = 0; i < strlen(s); i++)
        this->str[i] = s[i];
    this->str[strlen(s)] = '\0';
}

void assign_s(string_t *this, const string_t *str)
{
    assign_c(this, str->str);
}