/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** h file for my_printf
*/

#ifndef FUNCT_H
#define FUNCT_H

#include <stdio.h>
#include <stdarg.h>
#include "my.h"

void print_int(va_list ap, char *str, int i);
void print_binary(va_list ap, char *str, int i);
void print_unsigned_int(va_list ap, char *str, int i);
void print_octal(va_list ap, char *str, int i);
void print_hexa(va_list ap, char *str, int i);
void print_Hexa(va_list ap, char *str, int i);
void print_char(va_list ap, char *str, int i);
void print_str(va_list ap, char *str, int i);
void print_str_mod(va_list ap, char *str, int i);
void print_pointer(va_list ap, char *str, int i);
void print_0(va_list ap, char *str, int i);
void print_0x(va_list ap, char *str, int i);
void print_0X(va_list ap, char *str, int i);

typedef struct funct_s {
    char c;
    void (*ptr)(va_list, char *, int);
} funct_t;

static funct_t funct[] = {
    {'d', print_int},
    {'i', print_int},
    {'u', print_unsigned_int},
    {'o', print_octal},
    {'x', print_hexa},
    {'X', print_Hexa},
    {'c', print_char},
    {'s', print_str},
    {'S', print_str_mod},
    {'p', print_pointer},
    {'b', print_binary},
};

#endif