/*
** EPITECH PROJECT, 2019
** matchsticks.h
** File description:
** h file for matchsticks
*/

#ifndef MATCHSTICKS
#define MATCHSTICKS

#include "my.h"

typedef struct information_s {
    int line;
    int nb_matches;
    int a;
    size_t nb;
    int tmp;
    int height;
    int length;
    int done;
} information_t;

typedef struct map_s {
    char **map;
    int height;
    int length;
    int i;
} map_t;

information_t get_info_player1(char **map, int max_matches);

int get_int(char *str);

int matchsticks(int ac, char **av);

char **main_map(int ac, char **av);

void print_map(char **map);

void modify_map(int line, int nb_matches, char **map);

int my_putnbr(int nb);

information_t get_info_player2(char **map, int max_matches);

void get_matches_2(information_t *player, char **map, int max);

int check_line(int line, int nb_matches, char **map);

#endif