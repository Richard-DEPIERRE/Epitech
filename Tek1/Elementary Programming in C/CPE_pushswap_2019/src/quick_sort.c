/*
** EPITECH PROJECT, 2019
** quick_sort
** File description:
** quick_sort algorithm
*/

#include "push_swap.h"

void swap(int *ln_a, int start, int end)
{
    int tmp = ln_a[start];

    ln_a[start] = ln_a[end];
    ln_a[end] = tmp;
}

void partition(int *ln_a, int start, int end, int *pos)
{
    int i = start - 1;
    int j = start;
    int pivot = ln_a[end];

    for (; j < end; j += 1)
        if (pivot > ln_a[j]) {
            i += 1;
            swap(ln_a, i, j);
        }
    i += 1;
    swap(ln_a, i, end);
    *pos = i;
}

void quick_sort(int *ln_a, int start, int end)
{
    int pos = 0;

    if (end > start) {
        partition(ln_a, start, end, &pos);
        quick_sort(ln_a, start, pos - 1);
        quick_sort(ln_a, pos + 1, end);
    }
}