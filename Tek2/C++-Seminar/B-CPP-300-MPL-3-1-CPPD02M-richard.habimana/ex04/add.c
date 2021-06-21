/*
** EPITECH PROJECT, 2021
** ex04
** File description:
** add
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "castmania.h"

int normal_add(int a, int b)
{
    return (a + b);
}

int absolute_add(int a, int b)
{
    if (a < 0)
        a *= (-1);
    if (b < 0)
        b *= (-1);
    return (a + b);
}

void exec_add(addition_t *operation)
{
    if (operation->add_type == NORMAL)
        operation->add_op.res = normal_add(operation->add_op.a,
        operation->add_op.b);
    else
        operation->add_op.res = absolute_add(operation->add_op.a,
        operation->add_op.b);
}