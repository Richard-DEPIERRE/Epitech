/*
** EPITECH PROJECT, 2021
** ex00
** File description:
** add
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mem_ptr.h"

void add_str(const char *str1, const char *str2, char **res)
{
    *res = malloc(sizeof(char) * (strlen(str1) + strlen(str2) + 1));
    for (int i = 0; i < strlen(str1); i++)
        res[0][i] = str1[i];
    for (int i = 0; i < strlen(str2); i++)
        res[0][i + strlen(str1)] = str2[i];
    res[0][strlen(str1) + strlen(str2)] = '\0';
}

void add_str_struct(str_op_t *str_op)
{
    int size = strlen(str_op->str1) + strlen(str_op->str2) + 1;
    str_op->res = malloc(sizeof(char) * size);
    for (int i = 0; i < strlen(str_op->str1); i++)
        str_op->res[i] = str_op->str1[i];
    for (int i = 0; i < strlen(str_op->str2); i++)
        str_op->res[i + strlen(str_op->str1)] = str_op->str2[i];
}