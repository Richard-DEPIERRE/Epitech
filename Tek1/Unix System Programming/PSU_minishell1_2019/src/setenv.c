/*
** EPITECH PROJECT, 2020
** setenv
** File description:
** setenv file
*/

#include "minishell.h"

int check_if_valid_input(minishell_t *mini)
{
    if (mini->table[1][0] < 'A' || (mini->table[1][0] > 'Z' &&
    mini->table[1][0] < 'a' && mini->table[1][0] != '_') ||
    mini->table[1][0] > 'z')
        return (2);
    for (int i = 1; mini->table[1][i]; i += 1)
        if (mini->table[1][i] < '0' || (mini->table[1][i] > '9' &&
        mini->table[1][i] != '=' && mini->table[1][i] < 'A') ||
        (mini->table[1][i] > 'Z' && mini->table[1][i] < 'a' &&
        mini->table[1][i] != '_') || mini->table[1][i] > 'z')
            return (1);
    if (!mini->table[2])
        return (0);
    for (int i = 0; mini->table[2][i]; i += 2)
        if (mini->table[2][i] < '0' || (mini->table[2][i] > '9' &&
        mini->table[2][i] != '=' && mini->table[2][i] < 'A') ||
        (mini->table[2][i] > 'Z' && mini->table[2][i] < 'a' &&
        mini->table[2][i] != '_') || mini->table[2][i] > 'z')
            return (1);
    return (0);
}

void add_nodes_for_setenv(minishell_t *mini)
{
    node_t *tmp = mini->head;

    while (my_strcmp(mini->table[1], tmp->name) != 0 && tmp->next != NULL)
        tmp = tmp->next;
    if (tmp->next == NULL) {
        if (!mini->table[2])
            mini->head = add_nodes(my_strcat(my_strcat(mini->table[1], "="),
            "\0"), mini->head);
        else
            mini->head = add_nodes(my_strcat(my_strcat(mini->table[1], "="),
            mini->table[2]), mini->head);
    } else {
        if (!mini->table[2]) {
            free(tmp->str);
            tmp->str = malloc(sizeof(char));
            tmp->str[0] = '\0';
        } else {
            free(tmp->str);
            tmp->str = my_strcpy(mini->table[2], tmp->str);
        }
    }
}

void setenv_function(minishell_t *mini)
{
    mini->tmp = 1;
    if (mini->table[1])
        mini->temp = check_if_valid_input(mini);
    if (!mini->table[1])
        display_reverse(mini->head);
    else if (mini->table[1] && mini->temp == 0)
        add_nodes_for_setenv(mini);
    else {
        if (mini->temp == 1) {
            write(1, "setenv: Variable name must ", 27);
            write(1, "contain alphanumeric characters.\n", 34);
        } else if (mini->temp == 2)
            write(1, "setenv: Variable name must begin with a letter.\n", 48);
    }
}