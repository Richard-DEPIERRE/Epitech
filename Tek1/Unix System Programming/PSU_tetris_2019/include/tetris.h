/*
** EPITECH PROJECT, 2019
** tetris.h
** File description:
** h file for tetris
*/

#ifndef TETRIS
#define TETRIS

#include "my.h"

typedef struct node_s {
    char *str;
    char *name;
    struct node_s *next;
} node_t;

typedef struct node_R_s {
    char **str;
    int x;
    int y;
    int length;
    int height;
    int number;
    struct node_R_s *next;
} node_R_t;

typedef struct pieces_s {
    int height;
    int length;
    int color;
    char *height_str;
    char *length_str;
    char *color_str;
} pieces_t;

typedef struct parse_s {
    char **table;
    int count;
    int j;
} parse_t;

typedef struct order_s {
    int a;
    int tmp;
    int pos;
    char one;
    char two;
} order_t;

typedef struct keys_s {
    char *name;
    int bol;
    char *str;
} keys_t;

typedef struct tetriminos_s {
    char **tetri;
    int x;
    int y;
} tetriminos_t;

typedef struct tetris_s {
    tetriminos_t *tetriminos;
    keys_t *keys;
    int tmp;
} tetris_t;

typedef struct bin_s {
    int height;
    int lenght;
    int level;
    int lines;
    int score;
    int seconds;
    int minutes;
    int x;
    int y;
    char *str;
    int tmp;
    int temp;
    int c;
    int nb;
    int tmp2;
    int tetrim;
    int timeout_int;
    WINDOW *win;
    clock_t t;
    clock_t t2;
    node_R_t *tetriminos;
    node_R_t *tetriminos2;
} bin_t;

int my_strlength(char *str);
int my_strcmp(char *str, char *str2);
int my_strcmp_mod(char *str, char *str2, char c);
char *my_strcpy(char *src, char *dest);
char **parse_string(char *str, char c);
int count_arguments(char *str, char c);
char *clean_string(char *str);
int my_getnbr(char const *str);
int my_put_nbr(int nb);

int get_map(char *str, char *name, tetris_t *tetris, bin_t *play);
void print_stats(char *str, tetris_t *tetris, bin_t *play);
void print_line(char *str, pieces_t *piece, tetris_t *tetris, bin_t *play);
void get_opt(int argc, char **argv, tetris_t *tetris);
int debug_tetris(tetris_t *tetris, bin_t *play);
int print_tetriminos(int tmp, tetris_t *tetris, bin_t *play);
void print_help(char *str);
void temporary_one(char **table, char **table2, char c, order_t *order);
int temporary_two(int tmp, char c);
void game_start(tetris_t *tetris, bin_t *play);
int my_getch(void);


void initialize(bin_t *bin);
void game_init(tetris_t *tetris, bin_t *play);
void game_create(tetris_t *tetris, bin_t *play);
void game_colors(void);
void game_print1(void);
void get_getch(tetris_t *tetris, bin_t *play);
void game_print5(tetris_t *tetris, bin_t *play);
void game_print4(bin_t *play);
void game_print3(bin_t *play);
void game_print2(void);


#endif