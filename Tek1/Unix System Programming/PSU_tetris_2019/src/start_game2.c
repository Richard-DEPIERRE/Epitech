/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "tetris.h"

void initialize(bin_t *bin)
{
    bin->height = 0;
    bin->lenght = 0;
    bin->level = 0;
    bin->lines = 0;
    bin->score = 0;
    bin->seconds = 0;
    bin->minutes = 0;
    bin->x = 0;
    bin->y = 0;
    bin->str = NULL;
    bin->tmp = 0;
    bin->temp = 0;
    bin->c =  0;
    bin->nb = 0;
    bin->tmp2 = 1;
    bin->tetrim = 0;
    bin->timeout_int = 1000;
}

void game_init(tetris_t *tetris, bin_t *play)
{
    if (!tetris->keys[6].str) {
        play->height = 10;
        play->lenght = 20;
    } else {
        for (play->tmp = 0; tetris->keys[6].str[play->tmp] != ','; play->tmp += 1);
        play->str = malloc(sizeof(char) * play->tmp);
        play->str[play->tmp - 1] = '\0';
        for (play->tmp = 0; tetris->keys[6].str[play->tmp] != ','; play->tmp += 1)
            play->str[play->tmp] = tetris->keys[6].str[play->tmp];
        play->height = my_getnbr(play->str);
        for (play->tmp += 1; tetris->keys[6].str[play->tmp]; play->tmp += 1)
            play->temp += 1;
        play->str = malloc(sizeof(char) * play->temp);
        play->str[play->temp - 1] = '\0';
        for (play->tmp = 0; tetris->keys[6].str[play->tmp] != ','; play->tmp += 1);
        play->temp = 0;
        for (play->tmp += 1; tetris->keys[6].str[play->tmp]; play->tmp += 1)
            play->str[play->temp++] = tetris->keys[6].str[play->tmp];
        play->lenght = my_getnbr(play->str);
    }
}

void game_create(tetris_t *tetris, bin_t *play)
{
    if (tetris->keys[0].str)
        play->level = my_getnbr(tetris->keys[0].str);
    if (my_strcmp("(space)", tetris->keys[5].str) == 0)
        tetris->keys[5].str[0] = ' ';
    play->win = initscr();
    getmaxyx(stdscr, play->y, play->x);
    if (play->y <= play->height * 2 || play->x <= 34 + play->lenght * 2) {

        endwin();
        write(2, "Please, change your terminal size and try again.\n", 49);
        return;
    }
    cbreak();
    noecho();
    timeout(play->timeout_int);
    curs_set(FALSE);
    keypad(stdscr, TRUE);
}

void game_colors(void)
{;
    if (has_colors() == FALSE) {
        endwin();
        puts("Your terminal does not support color");
        exit(1);
    }
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
}

void game_print1(void)
{
    attron(COLOR_PAIR(1));
    mvprintw(0, 0, "* * * ");
    mvprintw(1, 0, "  *   ");
    mvprintw(2, 0, "  *   ");
    mvprintw(3, 0, "  *   ");
    mvprintw(4, 0, "  *   ");
    mvprintw(0, 12, "* * * ");
    mvprintw(1, 12, "  *   ");
    mvprintw(2, 12, "  *   ");
    mvprintw(3, 12, "  *   ");
    mvprintw(4, 12, "  *   ");
    mvprintw(0, 24, "* ");
    mvprintw(1, 24, "* ");
    mvprintw(2, 24, "* ");
    mvprintw(3, 24, "* ");
    mvprintw(4, 24, "* ");
    attroff(COLOR_PAIR(1));
}