/*
** EPITECH PROJECT, 2019
** bsq
** File description:
** bsq header
*/

#ifndef BSQ_H
#define BSQ_H

typedef struct bsq_s {
    int i;
    int j;
    int length;
    int tmp;
    int line;
    int h;
    int *table;
    char *Height;
}bsq_t;

void create_tab(char *str, int *table, int i, int j);

void print_line(char *str, int size);

void calc_pos_biggest_square(char *str, int height, int length, int size);

void convert_map(char *str, int size);

int biggest_square(int *tab, int height, int length, int *pos_biggest_nb);

void print_square(int pos, char *str, int count, int size);

int error_lines(char *str, int size);

void convert_map2(bsq_t bsq, char *str, int size);

#endif /* !BSQ_H */
