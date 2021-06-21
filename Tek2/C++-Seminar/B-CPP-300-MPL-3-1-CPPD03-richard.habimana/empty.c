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

int empty(const string_t *this)
{
    if (!this->str)
        return (1);
    if (strlen(this->str))
        return (0);
    return (1);
}