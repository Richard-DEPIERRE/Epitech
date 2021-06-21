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

bool list_del_elem_at_front(list_t *front_ptr)
{
    if (!(*front_ptr))
        return (false);
    (*front_ptr) = (*front_ptr)->next;
    return (true);
}

bool list_del_elem_at_back(list_t *front_ptr)
{
    node_t *tmp = NULL;
    if (!(*front_ptr))
        return (false);
    tmp = (*front_ptr);
    if (!(tmp->next))
        (*front_ptr) = NULL;
    for (; tmp->next->next; tmp = tmp->next);
    tmp->next = NULL;
    return (true);
}

bool list_del_elem_at_position(list_t *front_ptr , unsigned int position)
{
    node_t *node = (*front_ptr);

    if (!(*front_ptr))
        return (false);
    if (!position)
        return list_del_elem_at_front(front_ptr);
    for (unsigned int i = 0; i < position - 1 && node; node = node->next)
        i++;
    if (!node || !node->next)
        return (false);
    node->next = node->next->next;
    return (true);
}