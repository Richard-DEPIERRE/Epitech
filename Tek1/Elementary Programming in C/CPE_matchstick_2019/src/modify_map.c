/*
** EPITECH PROJECT, 2020
** modify_map
** File description:
** modifying map
*/

#include "matchsticks.h"

void modify_map(int line, int nb_matches, char **map)
{
    int count = 0;

    for (; map[line][count]; count += 1);
    for (int i = count; i >= 0; i -= 1) {
        if (nb_matches <= 0)
            break;
        if (map[line][i] == '|') {
            map[line][i] = ' ';
            nb_matches -= 1;
        }
    }
}