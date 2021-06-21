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

unsigned int double_list_get_size(double_list_t list)
{
    int i = 0;

    for (doublelist_node_t *tmp = list; tmp; tmp = tmp->next, i++);
    return i;
}

bool double_list_is_empty(double_list_t list)
{
    if (list)
        return (false);
    return (true);
}

void double_list_dump(double_list_t list)
{
    for (doublelist_node_t *tmp = list; tmp; tmp = tmp->next)
        printf("%f\n", tmp->value);
}