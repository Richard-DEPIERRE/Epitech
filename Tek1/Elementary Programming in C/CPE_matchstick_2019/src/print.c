/*
** EPITECH PROJECT, 2020
** print
** File description:
** print anthing that needs printing
*/

#include "matchsticks.h"

void print_map(char **map)
{
    for (int i = 0; map[i]; i += 1)
        for (int j = 0; map[i][j]; j += 1)
            write(1, &map[i][j], 1);
}