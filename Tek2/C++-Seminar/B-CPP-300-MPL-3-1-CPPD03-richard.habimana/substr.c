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

void get_offset(const string_t *this, int *offset, int *length)
{
    if ((int)(strlen(this->str)) + (*offset) < 0)
        (*offset) = 0;
    else if ((*offset) < 0 && (int)(strlen(this->str)) + (*offset) >= 0)
        (*offset) = (int)(strlen(this->str)) + (*offset);
    if ((*length) < 0) {
        (*offset) += (*length);
        (*length) *= -1;
    }
}

string_t *substr(const string_t *this, int offset, int length)
{
    char *tmp = NULL;
    string_t *str = NULL;

    get_offset(this, &offset, &length);
    if (offset <= (int)(strlen(this->str)) && offset >= 0) {
        tmp = malloc(sizeof(char) * (length + 1));
        for (int i = offset; i < (int)(strlen(this->str)) && i -
        offset < length; i++)
            tmp[i - offset] = this->str[i];
        tmp[length] = '\0';
    } else {
        tmp = malloc(sizeof(char) * 1);
        tmp[0] = '\0';
    }
    str = malloc(sizeof(string_t));
    string_init(str, tmp);
    free(tmp);
    return (str);
}