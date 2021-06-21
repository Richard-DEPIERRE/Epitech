/*
** EPITECH PROJECT, 2019
** exec
** File description:
** execution file
*/

#include "push_swap.h"

void h_text(void)
{
    write(1, "USAGE\n\t./my_push_swap\nDESCRIPTION\n\t", 37);
    write(1, "Sort numbers in order from smallest to biggest\n\0", 48);
}

void pb(int *ln_a, int *ln_b, int size)
{
    int tmp = 0;

    tmp = ln_a[0];
    for (int i = 0; i < size - 1; i += 1)
        ln_a[i] = ln_a[i + 1];
    for (int i = size - 1; i > 0; i -= 1)
        ln_b[i] = ln_b[i - 1];
    ln_a[size - 1] = 0;
    ln_b[0] = tmp;
}

void ra(int *ln_a, int size)
{
    int tmp;

    tmp = ln_a[0];
    for (int i = 0; i < size - 1; i += 1)
        ln_a[i] = ln_a[i + 1];
    ln_a[size - 1] = tmp;
}

void pa(int *ln_a, int *ln_b, int size)
{
    int tmp = 0;

    tmp = ln_b[0];
    for (int i = 0; i < size - 1; i += 1)
        ln_b[i] = ln_b[i + 1];
    for (int i = size - 1; i > 0; i -= 1)
        ln_a[i] = ln_a[i - 1];
    ln_b[size - 1] = 0;
    ln_a[0] = tmp;
}

void sa(int *ln_a)
{
    int tmp = ln_a[0];

    ln_a[0] = ln_a[1];
    ln_a[1] = tmp;
}

int error_push_swap(int ac, char **av)
{
    if (ac == 2) {
        write(1, "\n", 1);
        return (1);
    }
    if (ac <= 1)
        return (84);
    for (int i = 1; av[i]; i += 1) {
        if (my_getnbr(av[i]) == -99999999)
            return 84;
    }
    return (0);
}