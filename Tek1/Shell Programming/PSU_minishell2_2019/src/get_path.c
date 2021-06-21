/*
** EPITECH PROJECT, 2020
** get_path
** File description:
** gets path
*/

#include "minishell.h"

void get_path(minishell_t *mini, char **env)
{
    for (int i = 0; env[i]; i += 1)
        if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T')
            mini->envi = parse_string(env[i] + 5, ':');
}