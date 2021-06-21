/*
** EPITECH PROJECT, 2020
** funct3
** File description:
** third file for functions
*/

#include "my_ls.h"

void my_putlong(long nb)
{
    char tmp = 0;

    if (nb < 0) {
        nb = nb * (-1);
        write(1, "-\0", 2);
    }
    if (nb >= 10) {
        my_putlong(nb / 10);
    }
    nb = nb % 10;
    tmp = nb + 48;
    write(1, &tmp, 1);
}

void my_putnb(int nb)
{
    char tmp = 0;

    if (nb < 0) {
        nb = nb * (-1);
        write(1, "-\0", 2);
    }
    if (nb >= 10) {
        my_putnb(nb / 10);
    }
    nb = nb % 10;
    tmp = nb + 48;
    write(1, &tmp, 1);
}