/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD01-richard.habimana
** File description:
** menger
*/

#include "menger.h"

void nothing(void)
{
    return;
}

void meng(int size, int level, int x, int y)
{
    printf("%03d %03d %03d\n", size, size + x, size + y);
    for (int a = 0; a < 3 && (level > 1); a += 1)
        for (int b = 0; b < 3; b += 1)
            (a != 1 || b != 1) ? meng(size / 3, level - 1,
            a * size + x, b * size + y) : nothing();
}