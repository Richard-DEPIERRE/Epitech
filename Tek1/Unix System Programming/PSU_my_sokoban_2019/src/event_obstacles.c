/*
** EPITECH PROJECT, 2019
** event_obstacles
** File description:
** file for obstacles events
*/

#include "sokoban.h"

char *int_to_str(int nb)
{
    char *str = malloc(sizeof(char) * 2);

    str[0] = nb + 48;
    str[1] = '\0';
    return (str);
}

void move_p(main_t *w, int move, int y, int x)
{
    if (w->tmp == move && w->map.map[w->pos.y + y]
    [w->pos.x + x] != '#') {
        if (w->X_or_not != 0 && w->map.map[w->pos.y + (2 * y)]
        [w->pos.x + (2 * x)] == '#') {
            w->pos.y = w->pos.y;
            w->pos.x = w->pos.x;
        } else if (w->X_or_not != 0 && w->X_or_not2 != 0) {
            w->pos.y = w->pos.y;
            w->pos.x = w->pos.x;
        } else {
            w->pos.y += y;
            w->pos.x += x;
        }
        w->nb_of_move += 1;
    }
}

void calculate_p(main_t *w, int move, int y, int x)
{
    w->X_or_not = 0;
    w->X_or_not2 = 0;
    for (int i = 0; w->pos_X[i] != -2; i += 2) {
        if ((w->pos.y + (y)) == w->pos_X[i] &&
        (w->pos.x + (x)) == w->pos_X[i + 1])
            w->X_or_not += 1;
        else
            w->X_or_not += 0;
    }
    for (int i = 0; w->pos_X[i] != -2; i += 2) {
        if ((w->pos.y + (2 * y)) == w->pos_X[i] &&
        (w->pos.x + (2 * x)) == w->pos_X[i + 1])
            w->X_or_not2 += 1;
        else
            w->X_or_not2 += 0;
    }
    move_p(w, move, y, x);
}

void move_without_obstacle(main_t *w, int move, int y, int x)
{
    w->X_or_not = 0;
    for (int i = 0; w->pos_X[i] != -2; i += 2) {
        if ((w->pos.y + (2 * y)) == w->pos_X[i] &&
        (w->pos.x + (2 * x)) == w->pos_X[i + 1])
            w->X_or_not += 1;
        else
            w->X_or_not += 0;
    }
    if (w->tmp == move && w->map.map[w->pos.y + (2 * y)]
    [w->pos.x + (2 * x)] != '#' && w->X_or_not == 0)
        for (int i = 0; w->pos_X[i] != -2; i += 2)
            if ((w->pos.y + y) == w->pos_X[i] &&
            (w->pos.x + x) == w->pos_X[i + 1]) {
                w->pos_X[i] += y;
                w->pos_X[i + 1] += x;
            }
}