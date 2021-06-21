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

char at(const string_t *this, size_t pos)
{
    size_t i = 0;
    for (; i < pos && i < strlen(this->str); i++);
    if (i == strlen(this->str))
        return (-1);
    return (this->str[i]);
}