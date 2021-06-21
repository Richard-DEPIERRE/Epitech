/*
** EPITECH PROJECT, 2019
** calculate
** File description:
** every calculation needed
*/

#include "sokoban.h"

void fill_map(main_t *screen)
{
    int count = 0;
    int j = 0;
    int i = 0;

    for (i = 0; i < screen->map.height; i += 1) {
        for (j = 0;screen->map.str[count] != '\n'
        && screen->map.str[count] != '\0'; j += 1) {
            screen->map.map[i][j] = screen->map.str[count];
            count += 1;
        }
        screen->map.map[i][j] = '\0';
        count += 1;
    }
    screen->map.map[i] = NULL;
}

void make_arr_from_str(main_t *screen)
{
    int count = 0;
    int j = 0;

    screen->map.height = 0;
    for (int i = 0; i < screen->map.size; i += 1)
        if (screen->map.str[i] == '\n') {
            screen->map.height += 1;
        }
    screen->map.height += 1;
    screen->map.map = malloc(sizeof(char *) * (screen->map.height + 1));
    for (int i = 0; i < screen->map.height; i += 1) {
        for (j = 0; screen->map.str[count] != '\n'
        && screen->map.str[count] != '\0'; j += 1) {
            count += 1;
        }
        screen->map.map[i] = malloc(sizeof(char) * (j + 1));
        count += 1;
    }
    calculate_longest_width(screen);
    fill_map(screen);
}