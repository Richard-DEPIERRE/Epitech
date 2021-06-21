/*
** EPITECH PROJECT, 2019
** draw
** File description:
** drawing file
*/

#include "my_hunter.h"

void draw_base(all_struct_t *hunter)
{
    sfRenderWindow_clear(hunter->prim.w, sfBlack);
    sfRenderWindow_drawSprite(hunter->prim.w, hunter->back.sprite, NULL);
    sfRenderWindow_drawSprite(hunter->prim.w, hunter->ufo.sprite, NULL);
    sfRenderWindow_drawSprite(hunter->prim.w, hunter->ufo2.sprite, NULL);
    sfRenderWindow_drawText(hunter->prim.w, hunter->score.text, NULL);
    sfRenderWindow_drawText(hunter->prim.w, hunter->high_score.text, NULL);
    sfRenderWindow_drawText(hunter->prim.w, hunter->time.text, NULL);
    sfRenderWindow_drawSprite(hunter->prim.w, hunter->scope.sprite, NULL);
    set_sprites(hunter);
    sfRenderWindow_display(hunter->prim.w);
}

void set_pause(all_struct_t *hunter)
{
    sfText_setString(hunter->time.text, my_strcat("Time : ", \
    my_putnbr(hunter->prim.Time)));
    sfSprite_setPosition(hunter->scope.sprite, hunter->scope.pos);
    hunter->scope.mouse_pos = sfMouse_getPositionRenderWindow(hunter->prim.w);
    hunter->scope.pos.x = hunter->scope.mouse_pos.x - 75;
    hunter->scope.pos.y = hunter->scope.mouse_pos.y - 75;
}

void draw_pause(all_struct_t *hunter)
{
    sfRenderWindow_clear(hunter->prim.w, sfBlack);
    sfRenderWindow_drawSprite(hunter->prim.w, hunter->back.sprite, NULL);
    sfRenderWindow_drawSprite(hunter->prim.w, hunter->ufo.sprite, NULL);
    sfRenderWindow_drawSprite(hunter->prim.w, hunter->ufo2.sprite, NULL);
    sfRenderWindow_drawText(hunter->prim.w, hunter->score.text, NULL);
    sfRenderWindow_drawText(hunter->prim.w, hunter->high_score.text, NULL);
    sfRenderWindow_drawText(hunter->prim.w, hunter->time.text, NULL);
    sfRenderWindow_drawSprite(hunter->prim.w, hunter->scope.sprite, NULL);
    set_pause(hunter);
    sfRenderWindow_display(hunter->prim.w);
}

void draw_everything(all_struct_t *hunter)
{
    if (hunter->prim.click == 1)
        draw_base(hunter);
    else if (hunter->prim.click == -1)
        draw_pause(hunter);
}