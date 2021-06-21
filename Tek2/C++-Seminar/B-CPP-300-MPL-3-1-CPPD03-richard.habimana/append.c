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

void append_c(string_t *this, const char *ap)
{
    int size = 0;
    char *s = NULL;

    if (!this->str)
        return assign_c(this, ap);
    s = malloc(sizeof(char) * (strlen(this->str) + 1));
    for (size_t i = 0; i < strlen(this->str); i++)
            s[i] = this->str[i];
    s[strlen(this->str)] = '\0';
    size = strlen(s) + strlen(ap) + 1;
    free(this->str);
    this->str = malloc(sizeof(char) * size);
    for (size_t i = 0; i < strlen(s); i++)
        this->str[i] = s[i];
    for (size_t i = 0; i < strlen(ap); i++)
        this->str[i + strlen(s)] = ap[i];
    this->str[strlen(s) + strlen(ap)] = '\0';
    free(s);
}

void append_s(string_t *this, const string_t *ap)
{
    append_c(this, ap->str);
}