/*
** EPITECH PROJECT, 2020
** my_commands
** File description:
** my own commands
*/

#include "minishell.h"

void check_if_my_commands(minishell_t *mini)
{
    if (my_strcmp("setenv", mini->table[0]) == 0 && mini->table[0][6] == '\0')
        setenv_function(mini);
    if (my_strcmp("unsetenv", mini->table[0]) == 0 && mini->table[0][8] == '\0')
        unsetenv_function(mini);
    if (my_strcmp("env", mini->table[0]) == 0 && mini->table[0][3] == '\0')
        env_function(mini);
    if (my_strcmp("cd", mini->table[0]) == 0 && mini->table[0][2] == '\0')
        cd_function(mini);
    if (my_strcmp("exit", mini->table[0]) == 0 && mini->table[0][4] == '\0')
        exit(0);
}