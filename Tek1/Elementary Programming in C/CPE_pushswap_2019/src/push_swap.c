/*
** EPITECH PROJECT, 2019
** push_swap
** File description:
** pushswap
*/

#include "push_swap.h"

void pushswap(int *ln_a, int *ln_b, int *tmp, int size)
{
    int count = size;

    quick_sort(tmp, 0, size - 1);
    for (int i = 0; i < size; i += 1) {
        while (ln_a[0] != tmp[i]) {
            ra(ln_a, count);
            write(1, "ra \0", 3);
        }
        pb(ln_a, ln_b, size);
        write(1, "pb \0", 3);
        count -= 1;
    }
    for (int i = 0; i < size - 1; i += 1) {
        pa(ln_a, ln_b, size);
        write(1, "pa \0", 3);
    }
    pa(ln_a, ln_b, size);
    write(1, "pa\n\0", 3);
}

int check_sort(int *ln_a, int size)
{
    for (int i = 0; i < size - 1; i += 1) {
        if (ln_a[i] > ln_a[i + 1]) {
            return 0;
        }
    }
    return 9;
}

int push_swap(int ac, char **av)
{
    int *ln_a = malloc(sizeof(int) * ac);
    int *tmp = malloc(sizeof(int) * ac);
    int *ln_b = malloc(sizeof(int) * ac);

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h'){
        h_text();
        return (0);
    }
    if (error_push_swap(ac, av) != 0)
        return (error_push_swap(ac, av));
    for (int i = 0; i < ac - 1; i += 1) {
        ln_a[i] = my_getnbr(av[i + 1]);
        tmp[i] = ln_a[i];
    }
    if (check_sort(ln_a, ac - 1) != 0)
        write(1, "\n", 1);
    else {
        pushswap(ln_a, ln_b, tmp, ac - 1);
    }
    return (0);
}