/*
** EPITECH PROJECT, 2021
** ex02
** File description:
** add
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void tab_to_2dtab(const int *tab, int length, int width, int ***res)
{
    int count = 0;
    (*res) = malloc(sizeof(int *) * length);
    for (int i = 0; i < length; i++)
        (*res)[i] = malloc(sizeof(int) * width);
    for (int i = 0; i < length; i++)
        for (int j = 0; j < width; j++)
            (*res)[i][j] = tab[count++];
}