/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "n4s.h"

void direction_two(info_t *info, char *tmp)
{
    if (atof(info->tab[15]) > 400)
        info->bolle = 0;
    wheel_dir(info, tmp);
    if (info->bolle == 0)
        car_forward(info, tmp);
    if (info->bolle == 1)
        car_backward(info, tmp);
}

void direction(info_t *info, char *tmp)
{
    if (atof(info->tab[3]) < 600)
        info->direction = (1 - (500 / (atof(info->tab[3]))));
    if (atof(info->tab[32]) < 280)
        info->direction = -(1 - (280 / (atof(info->tab[32]))));
    if (atof(info->tab[15]) < 400 || atof(info->tab[3]) < 50 ||
    atof(info->tab[32]) < 50) {
        if (atof(info->tab[3]) < atof(info->tab[32]))
            info->direction = 0.3;
        if (atof(info->tab[3]) > atof(info->tab[32]))
            info->direction = -0.3;
        info->speed = 0.5;
        info->bolle = 1;
    }
    direction_two(info, tmp);
}

void loop(info_t *info, int size, char *tmp)
{
    while (1) {
        if (info->bolle == 0)
            info->speed = 0.22;
        get_distance(info, size, tmp);
        if (atof(info->tab[15]) == 0)
            dprintf(1, "STOP_SIMULATION\n");
        else
            direction(info, tmp);
        if (my_strcmp(info->tab[35], "Track Cleared\0") == 0) {
            dprintf(1, "CAR_FORWARD:%f\n", 0.0);
            dprintf(1, "STOP_SIMULATION\n");
        }
    }
}

void init_n4s(info_t *info)
{
    info->lol = 0;
    info->bolle = 1;
    info->check = 0;
    info->speed = 0.25;
    info->max = -1;
    info->direction = 0.0;
    info->tab = malloc(sizeof(char *) * 4096);
    info->pos = malloc(sizeof(float) * 32);
}

int main(void)
{
    info_t *info = malloc(sizeof(info_t));
    char *tmp = NULL;
    size_t size = 0;
    init_n4s(info);

    dprintf(1, "START_SIMULATION\n");
    dprintf(2, "START_SIMULATION\n");
    while (getline(&tmp, &size, stdin) == -1) {
        dprintf(2, "error\n");
        info->lol += 1;
    }
    sleep(1);
    loop(info, size, tmp);
    return (0);
}