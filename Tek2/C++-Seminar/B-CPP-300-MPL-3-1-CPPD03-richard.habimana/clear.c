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

void clear(string_t *this)
{
    free(this->str);
    this->str = (char *)calloc(1, sizeof(char));
    this->str[0] = '\0';
}