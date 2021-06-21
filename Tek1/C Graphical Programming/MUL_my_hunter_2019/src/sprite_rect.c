/*
** EPITECH PROJECT, 2019
** my_hunter_1
** File description:
** file for my_hunter
*/

#include "my_hunter.h"

void move_rect(int max_left, int max_top, sprite_t *sprite)
{
    if (sprite->rect.left < max_left)
        sprite->rect.left += 376;
    if (sprite->rect.left == max_left && sprite->rect.top < max_top) {
        sprite->rect.left = 0;
        sprite->rect.top += 248;
    } else if (sprite->rect.left == max_left && sprite->rect.top == max_top) {
        sprite->rect.left = 0;
        sprite->rect.top = 0;
    }
}

void change_rect(all_struct_t *hunter)
{
    hunter->prim.time = sfClock_getElapsedTime(hunter->prim.clock);
    hunter->prim.seconds = hunter->prim.time.microseconds / 1000000.0;
    if (hunter->prim.seconds > 0.1) {
        move_rect(1504, 992, &hunter->ufo);
        move_rect(1504, 992, &hunter->ufo2);
        sfClock_restart(hunter->prim.clock);
    }
}

void change_time(all_struct_t *hunter)
{

    hunter->prim.time2 = sfClock_getElapsedTime(hunter->prim.clock2);
    hunter->prim.seconds2 = hunter->prim.time2.microseconds / 1000000.0;
    if (hunter->prim.seconds2 > 1) {
        hunter->prim.Time -= 1;
        sfClock_restart(hunter->prim.clock2);
    }
    sfText_setString(hunter->time.text, \
    my_strcat("Time : ", my_putnbr(hunter->prim.Time)));
}