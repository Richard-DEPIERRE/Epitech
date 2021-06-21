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

int integer_div(int a, int b)
{
    if (b == 0)
        return (0);
    return (a / b);
}

float decimale_div(int a, int b)
{
    if (b == 0)
        return (0);
    return (((double)a) / ((double)b));
}

void exec_div(division_t *operation)
{
    if (operation->div_type == INTEGER) {
        integer_op_t *int_op = operation->div_op;
        int_op->res = integer_div(int_op->a, int_op->b);
    } else {
        decimale_op_t *dec_op = operation->div_op;
        dec_op->res = decimale_div(dec_op->a, dec_op->b);
    }
}
