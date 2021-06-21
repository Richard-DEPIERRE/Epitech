/*
** EPITECH PROJECT, 2019
** draw
** File description:
** drawing file
*/

#include "my_runner.h"

void draw_base(all_struct_t *runner)
{
    sfRenderWindow_clear(runner->prim.w, sfBlack);
    sfRenderWindow_display(runner->prim.w);
}

void set_pause(all_struct_t *runner)
{
    sfText_setString(runner->time_text.text, my_strcat("Time : ", \
    my_putnbr(runner->prim.Time)));
}

void draw_pause(all_struct_t *runner)
{
    sfRenderWindow_clear(runner->prim.w, sfBlack);
    sfRenderWindow_display(runner->prim.w);
}

void draw_everything(all_struct_t *runner)
{
    sfRenderWindow_clear(runner->prim.w, sfBlack);
    for (int i = 0; i < 4; i += 1) {
        sfRenderWindow_drawSprite(runner->prim.w, runner->objects[i].sprite, \
        NULL);
    }
    sfRenderWindow_drawSprite(runner->prim.w, \
    runner->objects[runner->pos].sprite, NULL);
    if (runner->objects[5].type == JUMP)
        sfRenderWindow_drawSprite(runner->prim.w, runner->objects[6].sprite, \
        NULL);
    else
        sfRenderWindow_drawSprite(runner->prim.w, runner->objects[5].sprite, \
        NULL);
    for (int i = 0; runner->map.pos[i].x != -1; i += 1) {
        sfRenderWindow_drawSprite(runner->prim.w, \
        runner->objects[i + 7].sprite, NULL);
    }
    sfRenderWindow_drawSprite(runner->prim.w, runner->objects[4].sprite, NULL);
    sfRenderWindow_drawText(runner->prim.w, runner->score.text, NULL);
    sfRenderWindow_display(runner->prim.w);
}