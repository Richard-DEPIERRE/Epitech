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
#include "generic_list.h"

void *list_get_elem_at_front(list_t list)
{
    if (!list)
        return (0);
    return (list->value);
}

void *list_get_elem_at_back(list_t list)
{
    node_t *tmp = NULL;
    if (!list)
        return (0);
    tmp = list;
    for (; tmp->next; tmp = tmp->next);
    return (tmp->value);
}

void *list_get_elem_at_position(list_t list, unsigned int position)
{
    node_t *node = list;

    if (!list)
        return (0);
    if (!position)
        return list_get_elem_at_front(list);
    for (unsigned int i = 0; i < position && node; node = node->next)
        i++;
    if (!node)
        return (0);
    return (node->value);
}

node_t *list_get_first_node_with_value(list_t list, void *value,
value_comparator_t val_comp)
{
    node_t *node = list;

    if (!list)
        return (NULL);
    for (int i = 0; val_comp(value, node->value) != 0
    && node->next; node = node->next)
        i++;
    if (!node->next && val_comp(value, node->value) != 0)
        return (NULL);
    return (node);
}