/*
** EPITECH PROJECT, 2019
** bsq_calc
** File description:
** calculate bsq map
*/

#include "include/my.h"

void convert_map(char *str, int size)
{
    bsq_t bsq;
    bsq.i = 0;
    bsq.j = 0;
    bsq.length = 0;
    bsq.tmp = 0;
    bsq.line = 0;
    bsq.h = 0;
    bsq.Height = malloc(sizeof(char) * 6);

    for (; str[bsq.i] != '\n'; bsq.i += 1)
        bsq.Height[bsq.i] = str[bsq.i];
    bsq.Height[bsq.i] = '\0';
    bsq.h = my_getnbr(bsq.Height);
    bsq.i += 1;
    bsq.line = bsq.i;
    bsq.table = malloc(sizeof(int) * (size - bsq.i));
    convert_map2(bsq, str, size);
}

int calc_pos(int length, int i, int j)
{
    return (length * (i - 1)) + j;
}

int calc_min(int *tab, int i, int j, int length)
{
    int nb1 = tab[length * (i - 2) + (j - 1)];
    int nb2 = tab[length * (i - 1) + (j - 1)];
    int nb3 = tab[length * (i - 2) + j];

    if ( nb1 <= nb2 && nb1 <= nb3)
        return nb1;
    else if (nb2 <= nb1 && nb2 <= nb3)
        return nb2;
    else
        return nb3;
}

int calc_2(int pos, int pos_biggest_nb, int *tab, int minimum)
{
    if (tab[pos] == 0)
        tab[pos] = 0;
    else {
        tab[pos] = minimum + 1;
        if (tab[pos] > tab[pos_biggest_nb])
            pos_biggest_nb = pos;
    }
    return pos_biggest_nb;
}

int biggest_square(int *tab, int height, int length, int *pos_biggest_nb)
{
    int i = 0;
    int j = 0;
    int tmp = 0;
    int pos = 0;
    int minimum = 0;

    length += 1;
    for (i = 2; i <= height; i += 1)
        for (j = 1 ;j < length - 1; j += 1) {
            pos = calc_pos(length, i, j);
            minimum = calc_min(tab, i, j, length);
            *pos_biggest_nb = calc_2(pos, *pos_biggest_nb, tab, minimum);
        }
    return tab[*pos_biggest_nb];
}