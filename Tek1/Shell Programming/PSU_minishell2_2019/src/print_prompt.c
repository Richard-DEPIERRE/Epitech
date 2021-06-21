/*
** EPITECH PROJECT, 2020
** print_prompt
** File description:
** prints my prompt
*/

#include "minishell.h"

void print_prompt(void)
{
    char *str = NULL;

    if (isatty(0) == 1) {
        for (int i = 1; str == NULL; i += 1) {
            str = malloc(sizeof(char) * i);
            str = getcwd(str, i);
        }
        write(1, my_strcat(str, "/->"), my_strlength(str) + 3);
    }
}