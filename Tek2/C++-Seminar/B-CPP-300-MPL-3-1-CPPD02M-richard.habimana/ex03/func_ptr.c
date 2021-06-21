/*
** EPITECH PROJECT, 2021
** ex03
** File description:
** add
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "func_ptr.h"

void print_normal(const char *str)
{
    printf("%s\n", str);
}

void print_reverse(const char *str)
{
    for (int i = strlen(str) - 1; i >= 0; i--)
        printf("%c", str[i]);
    printf("\n");
}

void print_upper(const char *str)
{
    char tmp = 0;
    for (int i = 0; i < strlen(str); i++)
        if (str[i] >= 'a' && str[i] <= 'z') {
            tmp = str[i] - 32;
            printf("%c", tmp);
        } else
            printf("%c", str[i]);
    printf("\n");
}

void print_42(const char *str)
{
    printf("42\n");
}

void do_action(action_t action, const char *str)
{
    funct[action].ptr(str);
}