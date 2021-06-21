/*
** EPITECH PROJECT, 2019
** firtree
** File description:
** firtree
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void my_putchar(char c)
{
    write(1, &c, 1);
}

int stars_number(int level, int stars)
{
    if (level == 1) {
        stars = stars - 4;
    } else if (level > 1 && (level % 2) == 0) {
        stars = stars - (2 + level);
    } else if (level > 1 && (level % 2) != 0) {
        stars = stars - (2 + (level + 1));
    }
    return (stars);
}

void print_char(int spaces, int stars, char char1)
{
    for (int x = 0; x < spaces; x++) {
        my_putchar(' ');
    }
    for (int y = 0; y < stars; y++) {
        my_putchar(char1);
    }
    my_putchar('\n');
}

int total(int size)
{
    int total_length = size;
    int height;

    for (int level = 0; level <= size; level++) {
        height = 3 + level;
        for (int i = 0; i < height; i++) {
            total_length = total_length + 2;
            }
        total_length = stars_number(level, total_length);
    }
    total_length = total_length - 4;
    return (total_length);
}

void tronc(int size, int total_length)
{
    int tronc = 0;
    int spaces = 0;

    for (int i = 0; i < size; i++) {
        if (size == 1) {
            tronc = 1;
        } else if (size > 1 && size % 2 == 0) {
            tronc = size + 1;
        } else if (size > 1 && size % 2 != 0) {
            tronc = size;
        }
        spaces = ((total_length - tronc) / 2);
        print_char(spaces, tronc, '|');
    }
}

void tree(int size)
{
    int height;
    int total_length = 0;
    int stars = 1;
    int spaces = 0;

    total_length = total(size);
    for (int level = 1; level <= size; level++) {
        height = 3 + level;
        for (int i = 1; i <= height; i++) {
            spaces = ((total_length - stars) / 2);
            print_char(spaces, stars, '*');
            stars = stars + 2;
        }
        stars = stars_number(level, stars);
    }
    tronc(size, total_length);
}

int main(int ac, char **av)
{
    tree(atoi(av[1]));
    return 0;
}