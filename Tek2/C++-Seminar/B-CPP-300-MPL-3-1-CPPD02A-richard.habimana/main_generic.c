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

unsigned int list_get_size(list_t list)
{
    int i = 0;

    for (node_t *tmp = list; tmp; tmp = tmp->next, i++);
    return i;
}

bool list_is_empty(list_t list)
{
    if (list)
        return (false);
    return (true);
}

void list_dump(list_t list, value_displayer_t val_disp)
{
    for (node_t *tmp = list; tmp; tmp = tmp->next)
        val_disp(tmp->value);
}

void list_clear(list_t *front)
{
    (*front) = NULL;
}