/*
** EPITECH PROJECT, 2019
** main_menu
** File description:
** file for main menu
*/

#include "my_runner.h"

void draw_main_menu(all_struct_t *runner)
{
    sfRenderWindow_clear(runner->prim.w, sfBlack);
    for (int i = 0; i < 4; i += 1) {
        sfRenderWindow_drawSprite(runner->prim.w, runner->objects[i].sprite, \
        NULL);
    }
    sfRenderWindow_drawSprite(runner->prim.w, runner->objects[4].sprite, NULL);
    sfRenderWindow_drawSprite(runner->prim.w, \
    runner->objects[runner->pos].sprite, NULL);
    sfRenderWindow_display(runner->prim.w);
}

void main_menu(all_struct_t *runner)
{
    draw_main_menu(runner);
}

void change_rect(all_struct_t *runner)
{
    for (int i = 0; i < 5; i += 1) {
        if (runner->objects[i].pos.x <= -1920)
            runner->objects[i].pos.x = -4;
    }
    if (runner->objects[runner->map.size_map - 3].pos.x <= -120) {
        if (runner->infinite == 1)
            for (int i = 0; runner->map.pos[i].x != -1; i += 1) {
                runner->objects[i + 7].pos.x += (1920 * 3);
            }
        else
            runner->play = 3;
    }
    move_rect(runner);
}