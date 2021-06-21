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
/* void print_double_scien(va_list ap, char *str, int i);
void print_double_scien_short(va_list ap, char *str, int i);
void print_double(va_list ap, char *str, int i);
void print_dec(va_list ap, char *str, int i);
void print_dec_trail(va_list ap, char *str, int i);
void print_left_justify(va_list ap, char *str, int i);
void print_zero_pad(va_list ap, char *str, int i); */
//void print_sign_of_nb(va_list ap, char *str, int i);
//void print_sign_plus_minus(va_list ap, char *str, int i);

typedef struct funct_s {
    char c;
    void (*ptr)(va_list, char*, int);
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
    //{'f', print_double},
    //{'e', print_double_scien},
    //{'E', print_double_scien},
    //{'g', print_double_scien_short},
    //{'G', print_double_scien_short},
    //{'-', print_left_justify},
    //{'0', print_zero_pad},
    //{' ', print_sign_of_nb},
    //{'+', print_sign_plus_minus},
};

#endif