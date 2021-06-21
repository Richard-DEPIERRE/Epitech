/*
** EPITECH PROJECT, 2019
** winning
** File description:
** winning condition
*/

#include "sokoban.h"

int check_if_won(main_t *w)
{
    int win = 0;
    for (int j = 0; w->pos_O[j] != -2; j += 2)
        for (int i = 0; w->pos_X[i] != -2; i += 2)
            if ( w->pos_O[j] == w->pos_X[i] &&
            w->pos_O[j + 1] == w->pos_X[i + 1])
                win += 1;
    mvprintw(25, 25, int_to_str(w->nb_X));
    if (win == w->nb_X / 2)
        return (1);
    else
        return (0);
}

void check_if_lost2(main_t *w, int *lost, int i)
{
    if (w->map.map[w->pos_X[i] - 1][w->pos_X[i + 1]] == '#' &&
        w->map.map[w->pos_X[i]][w->pos_X[i + 1] + 1] == '#')
            *lost += 1;
    else if (w->map.map[w->pos_X[i] - 1][w->pos_X[i + 1]] == '#' &&
        w->map.map[w->pos_X[i]][w->pos_X[i + 1] - 1] == '#')
            *lost += 1;
}

int check_if_lost(main_t *w)
{
    int lost = 0;

    for (int i = 0; w->pos_X[i] != -2; i += 2) {
        if (w->map.map[w->pos_X[i] + 1][w->pos_X[i + 1]] == '#' &&
        w->map.map[w->pos_X[i]][w->pos_X[i + 1] + 1] == '#')
            lost += 1;
        else if (w->map.map[w->pos_X[i] + 1][w->pos_X[i + 1]] == '#' &&
        w->map.map[w->pos_X[i]][w->pos_X[i + 1] - 1] == '#')
            lost += 1;
        else
            check_if_lost2(w, &lost, i);
    }
    if (lost == w->nb_X / 2)
        return (1);
    else
        return (0);
}

void calculate_longest_width(main_t *screen)
{
    int count = 0;
    int j = 0;

    screen->map.max_width = 0;
    for (int i = 0; i < screen->map.height; i += 1) {
        for (j = 0; screen->map.str[count] != '\n'
        && screen->map.str[count] != '\0'; j += 1) {
            count += 1;
        }
        if (j > screen->map.max_width)
            screen->map.max_width = j;
        count += 1;
    }
}

void check_size(main_t *screen)
{
    if (LINES < screen->map.height ||
    COLS < screen->map.max_width)
        mvprintw(LINES / 2, COLS / 2, "Please enlarge terminal");
}