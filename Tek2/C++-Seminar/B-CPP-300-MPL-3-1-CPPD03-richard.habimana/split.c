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

string_t **split_s(const string_t *this, char separator)
{
    int size = 1;
    char *tmp = NULL;
    char sep[1];

    sep[0] = separator;
    for (size_t i = 0; i < strlen(this->str); i++)
        if (this->str[i] == separator)
            size++;
    tmp = strdup(this->str);
    char *tmp3 = tmp;
    string_t **end = malloc(sizeof(string_t *) * (size + 1));
    for (int i = 0; i < size; i++) {
        end[i] = malloc(sizeof(string_t));
        string_init(end[i], strsep(&tmp, sep));
    }
    end[size] = NULL;
    free(tmp3);
    return (end);
}

char **split_c(const string_t *this, char separator)
{
    int size = 1;
    char *tmp2 = NULL;
    char sep[1];
    sep[0] = separator;
    for (size_t i = 0; i < strlen(this->str); i++)
        if (this->str[i] == separator)
            size++;
    tmp2 = strdup(this->str);
    char *tmp3 = tmp2;
    char **end = malloc(sizeof(char *) * (size + 1));
    for (int i = 0; i < size; i++) {
        char *tmp = strsep(&tmp2, sep);
        end[i] = malloc(sizeof(char) * (strlen(tmp) + 1));
        for (size_t a = 0; a < strlen(tmp); a++)
            end[i][a] = tmp[a];
        end[i][strlen(tmp)] = '\0';
    }
    end[size] = NULL;
    free(tmp3);
    return (end);
}