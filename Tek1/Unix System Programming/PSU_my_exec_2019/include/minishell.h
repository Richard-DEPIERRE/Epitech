/*
** EPITECH PROJECT, 2019
** minishell.h
** File description:
** h file for minishell
*/

#ifndef MINISHELL1
#define MINISHELL1

#include "my.h"

typedef struct minishell_s {
    char **table;
    int nb_arguments;
} minishell_t;

int minishell1(int ac, char **av, char **env);

char *int_to_char(int nb);

#endif