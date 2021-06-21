/*
** EPITECH PROJECT, 2021
** ex04
** File description:
** add
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "double_list.h"

double double_list_get_elem_at_front(double_list_t list)
{
    if (!list)
        return (0);
    return (list->value);
}

double double_list_get_elem_at_back(double_list_t list)
{
    doublelist_node_t *tmp = NULL;
    if (!list)
        return (0);
    tmp = list;
    for (; tmp->next; tmp = tmp->next);
    return (tmp->value);
}

double double_list_get_elem_at_position(double_list_t list,
unsigned int position)
{
    doublelist_node_t *node = list;

    if (!list)
        return (0);
    if (!position)
        return double_list_get_elem_at_front(list);
    for (unsigned int i = 0; i < position && node; node = node->next)
        i++;
    if (!node)
        return (0);
    return (node->value);
}

doublelist_node_t *double_list_get_first_node_with_value(double_list_t
list, double value)
{
    doublelist_node_t *node = list;

    if (!list)
        return (NULL);
    for (int i = 0; node->value != value && node->next; node = node->next)
        i++;
    if (!node->next && node->value != value)
        return (NULL);
    return (node);
}