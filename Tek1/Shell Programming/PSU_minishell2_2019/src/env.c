/*
** EPITECH PROJECT, 2020
** setenv
** File description:
** setenv file
*/

#include "minishell.h"

void env_function(minishell_t *mini)
{
    mini->tmp = 1;
    if (!mini->table[1])
        display_reverse(mini->head);
    else {
        write(1, "env: ‘", 8);
        write(1, mini->table[1], my_strlength(mini->table[1]));
        write(1, "’: No such file or directory\n", 31);
    }
}