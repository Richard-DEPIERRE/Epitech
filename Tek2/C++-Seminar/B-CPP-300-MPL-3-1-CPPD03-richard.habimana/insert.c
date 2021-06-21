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

void insert_loop(string_t *this, const char *str, int *a)
{
    for (size_t b = 0; b < strlen(str); b++)
        this->str[(*a)++] = str[b];
}

void insert_c_two(string_t *this, size_t pos, const char *str, char *tmp)
{
    int a = 0;

    free(this->str);
    this->str = malloc(sizeof(char) * (strlen(tmp) + strlen(str) + 1));
    for (size_t i = 0; i < strlen(tmp); i++) {
        if (i == pos)
            insert_loop(this, str, &a);
        this->str[a++] = tmp[i];
    }
    this->str[strlen(tmp) + strlen(str)] = '\0';
}

void insert_c(string_t *this, size_t pos, const char *str)
{
    char *tmp = NULL;

    if (!str)
        return;
    if (!this->str)
        return (assign_c(this, str));
    if (pos >= strlen(this->str))
        return (append_c(this, str));
    tmp = malloc(sizeof(char) * (strlen(this->str) + 1));
    for (size_t i = 0; i < strlen(this->str); i++)
        tmp[i] = this->str[i];
    tmp[strlen(this->str)] = '\0';
    insert_c_two(this, pos, str, tmp);
    free(tmp);
}

void insert_s(string_t *this, size_t pos, const string_t *str)
{
    return (insert_c(this, pos, str->str));
}