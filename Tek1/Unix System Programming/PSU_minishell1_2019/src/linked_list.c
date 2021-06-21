/*
** EPITECH PROJECT, 2020
** node_list
** File description:
** file for node_lists
*/

#include "minishell.h"

void display_reverse(node_t *head)
{
    node_t *tmp = head;

    if (!tmp)
        return;
    if (tmp)
        display_reverse(tmp->next);
    write(1, tmp->name, my_strlength(tmp->name));
    write(1, "=", 1);
    write(1, tmp->str, my_strlength(tmp->str));
    write(1, "\n", 1);
}

void display(node_t *head)
{
    node_t *tmp = head;

    while (tmp) {
        write(1, tmp->str, my_strlength(tmp->str));
        write(1, "\n", 1);
        tmp = tmp->next;
    }
}

node_t *add_nodes(char *str, node_t *head)
{
    node_t *ln = NULL;
    int i = 0;
    int a = 0;
    ln = malloc(sizeof(*ln));

    for (i = 0; str[i] != '='; i += 1);
    ln->name = malloc(sizeof(char) * (i + 1));
    i++;
    for (a = 0; str[i]; i += 1)
        a += 1;
    ln->str = malloc(sizeof(char) * (a + 1));
    for (i = 0; str[i] != '='; i += 1)
        ln->name[i] = str[i];
    ln->name[i++] = '\0';
    a = 0;
    for (; str[i]; i += 1)
        ln->str[a++] = str[i];
    ln->str[a] = '\0';
    ln->next = head;
    return (ln);
}

node_t *add_node_at_end(char *str, node_t *head)
{
    node_t *ln = NULL;
    node_t *tmp = head;
    ln = malloc(sizeof(*ln));

    ln->str = str;
    ln->next = NULL;
    if (!head)
        return ln;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = ln;
    return (head);
}

node_t *delete_node(char *str, node_t *head)
{
    node_t *tmp = head;

    if (my_strcmp(tmp->name, str) == 0)
        return (tmp->next);
    while (my_strcmp(tmp->next->name, str) != 0 && tmp->next != NULL) {
        tmp = tmp->next;
    }
    if (tmp->next != NULL) {
        tmp->next = tmp->next->next;
        return (head);
    } else
        return (head);
}