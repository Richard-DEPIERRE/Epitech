/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD01-richard.habimana
** File description:
** menger
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <grp.h>
#include <dirent.h>
#include <pwd.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>

int pyramid_path(int size, const int **map)
{
    int **calc_map = malloc(sizeof(int*) * (size));
    for (int i = 0; i < size; i++) {
        calc_map[i] = malloc(sizeof(int) * (i + 1));
        for (int j = 0; j < i + 1; j ++)
            calc_map[i][j] = map[i][j];
    }
    for (int i = size - 2; i >= 0; i--)
        for (int j = 0; j < i + 1; j ++)
            if (calc_map[i+1][j] > calc_map[i+1][j+1])
                calc_map[i][j] += calc_map[i+1][j+1];
            else
                calc_map[i][j] += calc_map[i+1][j];
    return calc_map[0][0];
}