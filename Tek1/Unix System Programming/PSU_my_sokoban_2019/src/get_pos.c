/*
** EPITECH PROJECT, 2019
** get_pos
** File description:
** file to calculate multiple position
*/

#include "sokoban.h"

void get_pos_P(main_t *screen)
{
    for (int i = 0; i < screen->map.height; i += 1) {
        for (int j = 0; screen->map.map[i][j] != '\0'
        && screen->map.map[i][j] != '\n'; j += 1) {
            if (screen->map.map[i][j] == 'P') {
                screen->pos.x = j;
                screen->pos.y = i;
                break;
            }
        }
    }
}

void get_pos_O(main_t *screen)
{
    int count = 0;

    screen->nb_O = 0;
    for (int i = 0; i < screen->map.height; i += 1)
        for (int j = 0; screen->map.map[i][j] != '\0'
        && screen->map.map[i][j] != '\n'; j += 1)
            if (screen->map.map[i][j] == 'O')
                screen->nb_O += 2;
    screen->pos_O = malloc(sizeof(int) * (screen->nb_O + 2));
    for (int i = 0; i < screen->map.height; i += 1)
        for (int j = 0; screen->map.map[i][j] != '\0'
        && screen->map.map[i][j] != '\n'; j += 1)
            if (screen->map.map[i][j] == 'O'){
                screen->pos_O[count] = i;
                screen->pos_O[count + 1] = j;
                count += 2;
            }
    screen->pos_O[count] = -2;
    screen->pos_O[count + 1] = -2;
}

void get_pos_X(main_t *screen)
{
    int count = 0;

    screen->nb_X = 0;
    for (int i = 0; i < screen->map.height; i += 1)
        for (int j = 0; screen->map.map[i][j] != '\0'
        && screen->map.map[i][j] != '\n'; j += 1)
            if (screen->map.map[i][j] == 'X')
                screen->nb_X += 2;
    screen->pos_X = malloc(sizeof(int) * (screen->nb_X + 2));
    for (int i = 0; i < screen->map.height; i += 1)
        for (int j = 0; screen->map.map[i][j] != '\0'
        && screen->map.map[i][j] != '\n'; j += 1)
            if (screen->map.map[i][j] == 'X'){
                screen->pos_X[count] = i;
                screen->pos_X[count + 1] = j;
                count += 2;
            }
    screen->pos_X[count] = -2;
    screen->pos_X[count + 1] = -2;
}