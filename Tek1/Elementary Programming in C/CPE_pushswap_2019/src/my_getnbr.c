/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** my getnbr
*/

#include "push_swap.h"

int get_biggest_pos(int *ln_a, int size, int max, int *pos_max)
{
    int pos = 0;

    for (int i = 1; i < size; i += 1)
        if (ln_a[i] > ln_a[pos] && ln_a[i] <= max && i > *pos_max)
            pos = i;
    return (pos);
}

int my_strcmp2(int const *s1, int const *s2, int size)
{
    for (int i = 0; i < size; i += 1) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    }
    return (0);
}

void my_getnbr2(const char *str, int *nb, int *minus_count, int *count)
{
    int i = 0;

    for (; str[i] == '-' || str[i] == '+'; i += 1) {
        if (str[i] == '-')
            *minus_count += 1;
    }
    for (; str[i] != '\0'; i += 1) {
        if (str[i] < '0' || str[i] > '9') {
            *count = -4;
            break;
        }
        *nb = *nb * 10 + (str[i] - 48);
        *count += 1;
    }
}

int my_getnbr(char const *str)
{
    int minus_count = 0;
    int nb = 0;
    int count = 0;

    my_getnbr2(str, &nb, &minus_count, &count);
    if (minus_count % 2 == 1)
        nb = nb * (-1);
    if (count == 0 || count == -4)
        return (-99999999);
    return (nb);
}