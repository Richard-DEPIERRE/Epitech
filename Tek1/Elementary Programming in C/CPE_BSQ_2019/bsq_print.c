/*
** EPITECH PROJECT, 2019
** bsq_print
** File description:
** print bsq
*/

#include "include/my.h"

void print_square(int pos, char *str, int count, int size)
{
    int length = 0;
    int tmp = 0;

    for (; str[tmp] != '\n'; tmp += 1)
        length += 1;
    for (int i = 0; i < count; i += 1, pos -= (length + 1))
        for (int j = 0; j < count; j += 1)
            str[pos - j] = 'x';
    write(1, str, size - 1);
    my_printf("\n");
}

void print_line(char *str, int size)
{
    for (int i = 0; i < size; i += 1)
        if (str[i] == '.') {
            str[i] = 'x';
            break;
        }
    write(1, str, size);
}

void create_tab(char *str, int *table, int i, int j)
{
    while ( str[i] != '\0') {
        for (int a = 0; a < 3; a += 1) {
            if (str[i] == '.')
                table[j] = 1;
            if (str[i] == 'o')
                table[j] = 0;
            if (str[i] == '\n')
                table[j] = -3;
        }
        i += 1;
        j += 1;
    }
}

void convert_map2(bsq_t bsq, char *str, int size)
{

    for (int count = bsq.i; str[count] != '\n'; count += 1)
        bsq.length += 1;
    create_tab(str, bsq.table, bsq.i, bsq.j);
    if (bsq.h == 1 || bsq.length == 1)
        print_line(str + bsq.line, size - bsq.line);
    else {
        bsq.h = biggest_square(bsq.table, bsq.h, bsq.length, &bsq.tmp);
        print_square(bsq.tmp, str + bsq.line, bsq.h, size - bsq.line);
    }
    free(bsq.Height);
    free(bsq.table);
}