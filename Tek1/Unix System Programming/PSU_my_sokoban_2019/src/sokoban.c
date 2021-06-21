/*
** EPITECH PROJECT, 2019
** main
** File description:
** main for sokoban
*/

#include "sokoban.h"

void print_map(main_t *screen)
{
    for (int i = 0;screen->map.map[i]; i += 1)
        mvprintw(i, 0, screen->map.map[i]);
    for (int i = 0; screen->pos_O[i] != -2; i += 2)
        mvprintw(screen->pos_O[i], screen->pos_O[i + 1], "O");
    for (int i = 0; screen->pos_X[i] != -2; i += 2)
        mvprintw(screen->pos_X[i], screen->pos_X[i + 1], "X");
    mvprintw(screen->pos.y, screen->pos.x, "P");
}

void end_loop(main_t *screen)
{
    clear();
    for (int i = 0;screen->map.map[i]; i += 1)
        mvprintw(i, 0, screen->map.map[i]);
    for (int i = 0; screen->pos_O[i] != -2; i += 2)
        mvprintw(screen->pos_O[i], screen->pos_O[i + 1], "O");
    for (int i = 0; screen->pos_X[i] != -2; i += 2)
        mvprintw(screen->pos_X[i], screen->pos_X[i + 1], "X");
    mvprintw(screen->pos.y, screen->pos.x, "P");
    refresh();
    if (screen->tmp == KEY_BACKSPACE)
        endwin();
    if (check_if_won(screen) == 1) {
        screen->return_nb = 0;
        endwin();
    }
    if (check_if_lost(screen) == 1 && check_if_won(screen) == 0) {
        screen->return_nb = 1;
        endwin();
    }
}

void while_loop(main_t *screen)
{
    while (check_if_won(screen) == 0 && check_if_lost(screen) == 0) {
        if (LINES < screen->map.height &&
        COLS < screen->map.max_width) {
            clear();
            mvprintw(LINES / 2, COLS / 2 - 12, "Please enlarge terminal.");
            refresh();
        } else {
            clear();
            print_map(screen);
            refresh();
            screen->tmp = getch();
            if (screen->tmp == KEY_BACKSPACE)
                break;
            if (screen->tmp == 32)
                break;
            check_event_loop(screen);
        }
    }
    end_loop(screen);
}

int popup(main_t *screen)
{
    WINDOW *win;
    pos_t *pos_O;

    screen->X_or_not = 0;
    make_arr_from_str(screen);
    get_pos_P(screen);
    get_pos_O(screen);
    get_pos_X(screen);
    for (int i = 0; screen->pos_O[i] != -2; i += 2)
        screen->map.map[screen->pos_O[i]][screen->pos_O[i + 1]] = ' ';
    for (int i = 0; screen->pos_X[i] != -2; i += 2)
        screen->map.map[screen->pos_X[i]][screen->pos_X[i + 1]] = ' ';
    screen->map.map[screen->pos.y][screen->pos.x] = ' ';
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    while_loop(screen);
    if (screen->tmp == 32)
        popup(screen);
}

int make_sokoban(int ac, char **av)
{
    int errors = 0;
    main_t screen;
    char *map;

    screen.return_nb = 0;
    check_errors(ac, av, &errors, &screen);
    if (errors == 0 && screen.return_nb == 0)
        popup(&screen);
    if (errors == 84)
        screen.return_nb = 84;
    if (errors == 2)
        screen.return_nb = 0;
    return (screen.return_nb);
}