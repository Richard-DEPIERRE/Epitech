/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "n4s.h"

void wheel_dir(info_t *info, char *tmp)
{
    size_t size = 0;
    dprintf(1, "WHEELS_DIR:%f\n", info->direction);
    while (getline(&tmp, &size, stdin) == -1)
        info->lol += 1;
}

void car_forward(info_t *info, char *tmp)
{
    size_t size = 0;
    dprintf(1, "CAR_FORWARD:%f\n", info->speed);
    while (getline(&tmp, &size, stdin) == -1)
        info->lol += 1;
}

void car_backward(info_t *info, char *tmp)
{
    size_t size = 0;
    dprintf(1, "CAR_BACKWARDS:%f\n", info->speed);
    while (getline(&tmp, &size, stdin) == -1)
        info->lol += 1;
}

void get_distance(info_t *info, size_t size, char *tmp)
{
    for (int i = 0; tmp[i]; i += 1)
        tmp[i] = '\0';
    size = 0;
    dprintf(1, "GET_INFO_LIDAR\n");
    while (getline(&tmp, &size, stdin) == -1)
        info->lol += 1;
    info->tab = str_to_word_array(tmp);
    for (int i = 3; i < 35; i += 1)
        info->pos[i - 3] = atof(info->tab[i]);
}