/*
** EPITECH PROJECT, 2020
** map
** File description:
** map file
*/

#include "matchsticks.h"

char **create_map2(map_t map, int nb)
{
    for (int j = 1; j < map.height; j += 1) {
        map.i = 0;
        map.map[j][map.i++] = '*';
        for (int count = 1; count <= nb - j; count += 1)
            map.map[j][map.i++] = ' ';
        for (int count = 0; count < 2 * j - 1; count += 1)
            map.map[j][map.i++] = '|';
        for (int count = 1; count <= nb - j; count += 1)
            map.map[j][map.i++] = ' ';
        map.map[j][map.i++] = '*';
        map.map[j][map.i++] = '\n';
        map.map[j][map.i++] = '\0';
    }
    for (int i = 0; i < map.length - 1; i += 1)
        map.map[map.height][i] = '*';
    map.map[map.height][map.length - 1] = '\n';
    map.map[map.height][map.length] = '\0';
    map.map[map.height + 1] = NULL;
    return map.map;
}

char **create_map(int nb)
{
    map_t map;
    map.height = nb + 1;
    map.length = map.height * 2;
    map.i = 0;

    if (nb == -2147483646)
        return NULL;
    map.map = malloc(sizeof(char *) * (map.height + 2));
    for (int i = 0; i < map.height + 1; i += 1)
        map.map[i] = malloc(sizeof(char) * (map.length + 1));
    map.map[map.height + 1] = malloc(sizeof(char));
    for (int i = 0; i < map.length - 1; i += 1)
        map.map[0][i] = '*';
    map.map[0][map.length - 1] = '\n';
    map.map[0][map.length] = '\0';
    return (create_map2(map, nb));
}

char **main_map(int ac, char **av)
{
    int nb = 0;

    if (ac == 1)
        return (create_map(4));
    else if (ac == 3) {
        nb = get_int(av[1]);
        if (nb == -2147483646)
            return (NULL);
        else
            return (create_map(nb));
    }
    else
        return NULL;
}