/*
** EPITECH PROJECT, 2020
** game_over
** File description:
** game over file
*/

#include "my_runner.h"

void win(all_struct_t *runner)
{
    sfRenderWindow_clear(runner->prim.w, sfBlack);
    for (int i = 0; i < 4; i += 1) {
        sfRenderWindow_drawSprite(runner->prim.w, runner->objects[i].sprite, \
        NULL);
    }
    sfRenderWindow_drawSprite(runner->prim.w, runner->objects[4].sprite, NULL);
    sfRenderWindow_drawSprite(runner->prim.w, \
    runner->objects[runner->pos + 2].sprite, NULL);
    sfRenderWindow_display(runner->prim.w);
}

void game_over(all_struct_t *runner)
{
    if (runner->play == 2) {
        sfRenderWindow_clear(runner->prim.w, sfBlack);
        for (int i = 0; i < 4; i += 1) {
            sfRenderWindow_drawSprite(runner->prim.w,
            runner->objects[i].sprite, NULL);
        }
        sfRenderWindow_drawSprite(runner->prim.w,
        runner->objects[4].sprite, NULL);
        sfRenderWindow_drawSprite(runner->prim.w, \
        runner->objects[runner->pos + 1].sprite, NULL);
        sfRenderWindow_display(runner->prim.w);
    } else
        win(runner);
}