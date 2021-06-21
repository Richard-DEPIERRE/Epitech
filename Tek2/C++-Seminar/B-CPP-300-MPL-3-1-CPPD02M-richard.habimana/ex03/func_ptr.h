/*
** EPITECH PROJECT, 2018
** cpp_d02m
** File description:
** ex03
*/

#ifndef FUNC_PTR_H_
#define FUNC_PTR_H_

#include "func_ptr_enum.h"

typedef struct funct_s {
    action_t action;
    void (*ptr)(const char *);
} funct_t;

void print_normal(const char *str);

void print_reverse(const char *str);

void print_upper(const char *str);

void print_42(const char *str);

static funct_t funct[] = {
    {PRINT_NORMAL, print_normal},
    {PRINT_REVERSE, print_reverse},
    {PRINT_UPPER, print_upper},
    {PRINT_42, print_42}
};

#endif