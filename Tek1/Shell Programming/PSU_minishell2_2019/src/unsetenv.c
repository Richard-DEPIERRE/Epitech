/*
** EPITECH PROJECT, 2020
** unsetenv
** File description:
** unsetenv file
*/

#include "minishell.h"

void check_table(minishell_t *mini)
{
    node_t *tmp = mini->head;

    for (int i = 1; mini->table[i]; i += 1) {
        while (my_strcmp(mini->table[i], tmp->name) != 0 && tmp->next != NULL)
            tmp = tmp->next;
        if (tmp->next != NULL)
            mini->head = delete_node(mini->table[i], mini->head);
    }
}

void unsetenv_function(minishell_t *mini)
{
    mini->tmp = 1;
    if (!mini->table[1])
        write(1, "unsetenv: Too few arguments.\n", 29);
    else
        check_table(mini);
}