/*
** EPITECH PROJECT, 2019
** my_swap
** File description:
** swap int
*/

#include <unistd.h>

void    my_swap(int *a, int *b)
{
    int copy_number = 0;

    copy_number = *a;
    *a = *b;
    *b = copy_number;
}
