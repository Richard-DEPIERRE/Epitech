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

bool list_add_elem_at_front(list_t *front_ptr , void *elem)
{
    node_t *new_node = NULL;
    new_node = malloc(sizeof(*new_node));
    if (!new_node)
        return (false);
    new_node->value = elem;
    new_node->next = (*front_ptr);
    (*front_ptr) = new_node;
    return (true);
}

bool list_add_elem_at_back(list_t *front_ptr , void *elem)
{
    node_t *new_node = NULL;
    node_t *node = NULL;
    new_node = malloc(sizeof(*new_node));
    if (!new_node)
        return (false);
    new_node->value = elem;
    new_node->next = NULL;
    if (!(*front_ptr)) {
        (*front_ptr) = new_node;
        return (true);
    }
    for (node = (*front_ptr); node->next; node = node->next);
    node->next = new_node;
    return (true);
}

bool list_add_elem_at_position(list_t *front_ptr, void *elem,
unsigned int pos)
{
    node_t *new_node = NULL;
    node_t *node = (*front_ptr);

    if (!pos)
        return list_add_elem_at_front(front_ptr, elem);
    new_node = malloc(sizeof(*new_node));
    if (!new_node)
        return (false);
    new_node->value = elem;
    for (unsigned int i = 0; i < pos - 1 && node; node = node->next)
        i++;
    if (!node)
        return (false);
    new_node->next = node->next;
    node->next = new_node;
    return (true);
}