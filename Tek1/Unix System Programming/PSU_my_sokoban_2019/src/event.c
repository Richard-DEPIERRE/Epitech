/*
** EPITECH PROJECT, 2019
** event
** File description:
** file for event
*/

#include "sokoban.h"

void check_event_without(main_t *w, int move, int y, int x)
{
    w->X_or_not = 0;
    for (int i = 0; w->pos_X[i] != -2; i += 2) {
        if ((w->pos.y + (2 * y)) == w->pos_X[i] &&
        (w->pos.x + (2 * x)) == w->pos_X[i + 1])
            w->X_or_not += 1;
        else
            w->X_or_not += 0;
    }
    if (w->X_or_not == 0 && w->map.map[w->pos.y + y]
    [w->pos.x + x] != '#') {
        move_without_obstacle(w, move, y, x);
    }
    calculate_p(w, move, y, x);
}

void check_event_loop(main_t *screen)
{
    check_event_without(screen, KEY_UP, -1, 0);
    check_event_without(screen, KEY_DOWN, 1, 0);
    check_event_without(screen, KEY_RIGHT, 0, 1);
    check_event_without(screen, KEY_LEFT, 0, -1);
    if (screen->tmp == KEY_BACKSPACE)
        mvprintw(LINES - 10, COLS - 10, int_to_str(screen->nb_of_move));
}