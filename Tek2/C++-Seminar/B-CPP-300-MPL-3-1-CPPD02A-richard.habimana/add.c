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

bool double_list_add_elem_at_front(double_list_t *front_ptr , double elem)
{
    doublelist_node_t *new_node = NULL;
    new_node = malloc(sizeof(*new_node));
    if (!new_node)
        return (false);
    new_node->value = elem;
    new_node->next = (*front_ptr);
    (*front_ptr) = new_node;
    return (true);
}

bool double_list_add_elem_at_back(double_list_t *front_ptr , double elem)
{
    doublelist_node_t *new_node = NULL;
    doublelist_node_t *node = NULL;
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

bool double_list_add_elem_at_position(double_list_t *front_ptr,
double elem, unsigned int position)
{
    doublelist_node_t *new_node = NULL;
    doublelist_node_t *node = (*front_ptr);

    if (!position)
        return double_list_add_elem_at_front(front_ptr, elem);
    new_node = malloc(sizeof(*new_node));
    if (!new_node)
        return (false);
    new_node->value = elem;
    for (unsigned int i = 0; i < position - 1 && node; node = node->next)
        i++;
    if (!node)
        return (false);
    new_node->next = node->next;
    node->next = new_node;
    return (true);
}