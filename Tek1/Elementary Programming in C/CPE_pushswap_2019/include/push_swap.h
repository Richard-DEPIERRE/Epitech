/*
** EPITECH PROJECT, 2019
** my_hunter.h
** File description:
** h file for my_hunter
*/

#ifndef PUSH_SWAP
#define PUSH_SWAP

#include "my.h"

typedef struct list_s {
    int nb;
    struct list_s * next;
} list_t;

void pb(int *ln_a, int *ln_b, int size);

void rra(int *ln_a, int size);

void sa(int *ln_a);

void ra(int *ln_a, int size);

void pa(int *ln_a, int *ln_b, int size);

int error_push_swap(int ac, char **av);

int check_sort(int *ln_a, int size);

int push_swap(int ac, char **av);

void h_text(void);

void quick_sort(int *ln_a, int start, int end);

int my_strcmp2(int const *s1, int const *s2, int size);

int get_biggest_pos(int *ln_a, int size, int max, int *pos_max);

#endif