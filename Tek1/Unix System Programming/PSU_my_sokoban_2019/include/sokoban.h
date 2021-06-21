/*
** EPITECH PROJECT, 2019
** popup
** File description:
** popup.h
*/

#ifndef POPUP_H
#define POPUP_H

#include "my.h"

typedef struct pos_s {
    int x;
    int y;
} pos_t;

typedef struct map_s {
    char **map;
    char *str;
    int height;
    int max_width;
    int size;
} map_t;

typedef struct main_s {
    pos_t pos;
    map_t map;
    int *pos_O;
    int *pos_X;
    int tmp;
    int X_or_not;
    int X_or_not2;
    int count;
    int nb_O;
    int nb_X;
    int nb_of_move;
    int return_nb;
} main_t;

void check_errors(int ac, char **av, int *errors, main_t *screen);

int make_sokoban(int ac, char **av);

void make_arr_from_str(main_t *screen);

void check_event_loop(main_t *screen);

void move_without_obstacle(main_t *w, int move, int y, int x);

void calculate_p(main_t *w, int move, int y, int x);

void check_event_without(main_t *screen, int move, int y, int x);

void get_pos_X(main_t *screen);

void get_pos_O(main_t *screen);

void get_pos_P(main_t *screen);

char *int_to_str(int nb);

int check_if_won(main_t *w);

int check_if_lost(main_t *w);

void calculate_longest_width(main_t *screen);

#endif /* !POPUP_H */
