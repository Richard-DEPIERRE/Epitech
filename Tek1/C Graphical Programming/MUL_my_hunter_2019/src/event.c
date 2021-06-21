/*
** EPITECH PROJECT, 2019
** my_hunter_5
** File description:
** event file
*/

#include "my_hunter.h"

void get_pos(prim_struct_t *prim, sprite_t *sp)
{
    if (sp->mouse_pos.x >= sp->pos.x && sp->mouse_pos.x <= sp->pos.x + 376)
        if (sp->mouse_pos.y >= sp->pos.y && \
        sp->mouse_pos.y <= sp->pos.y + 248) {
            sp->tmp = 5;
            prim->Score += 1;
        }
}

void key_pressed(all_struct_t *hunter)
{
    hunter->game_over.mouse_pos = \
    sfMouse_getPositionRenderWindow(hunter->prim.w);
    if (hunter->prim.event.key.code == sfKeySpace) {
        hunter->prim.main_menu = 0;
        hunter->prim.Time = 60;
        hunter->prim.Score = 0;
    }
    if (hunter->main_menu.mouse_pos.x >=  0 && \
    hunter->main_menu.mouse_pos.x <= 70)
        if (hunter->main_menu.mouse_pos.y >= 0 && \
        hunter->main_menu.mouse_pos.y <= 90)
            sfRenderWindow_close(hunter->prim.w);
    if (hunter->main_menu.mouse_pos.x >=  500 && \
    hunter->main_menu.mouse_pos.x <= 870)
        if (hunter->main_menu.mouse_pos.y >= 523 && \
        hunter->main_menu.mouse_pos.y <= 700) {
            hunter->prim.main_menu = 0;
            hunter->prim.Time = 60;
        }
}

void main_event_loop(all_struct_t *hunter)
{
    if (hunter->prim.event.type == sfEvtMouseButtonPressed) {
            hunter->ufo.mouse_pos = \
            sfMouse_getPositionRenderWindow(hunter->prim.w);
            hunter->ufo2.mouse_pos = \
            sfMouse_getPositionRenderWindow(hunter->prim.w);
            get_pos(&hunter->prim, &hunter->ufo);
            get_pos(&hunter->prim, &hunter->ufo2);
            check_click(hunter);
            sfText_setString(hunter->score.text, \
            my_strcat("Score: ", my_putnbr(hunter->prim.Score)));
    }
}

void event_loop(all_struct_t *hunter)
{
    while (sfRenderWindow_pollEvent(hunter->prim.w, &hunter->prim.event)) {
        if (hunter->prim.event.type == sfEvtClosed)
            sfRenderWindow_close(hunter->prim.w);
        if (hunter->prim.event.key.code == sfKeyEscape)
            sfRenderWindow_close(hunter->prim.w);
        if (hunter->prim.event.key.code == sfKeyR) {
            hunter->prim.main_menu = 0;
            hunter->prim.Time = 60;
            hunter->prim.Score = 0;
        }
        if (hunter->prim.event.type == sfEvtMouseButtonPressed\
        && hunter->prim.Time < 0)
            key_pressed(hunter);
        else if (hunter->prim.event.type == sfEvtMouseButtonPressed\
        && hunter->prim.main_menu == 0)
            main_menu_loop(hunter);
        else
            main_event_loop(hunter);
    }
}

void game_over(all_struct_t *hunter)
{
    check_high_score(hunter);
    sfRenderWindow_clear(hunter->prim.w, sfBlack);
    sfRenderWindow_drawSprite(hunter->prim.w, hunter->game_over.sprite, NULL);
    sfRenderWindow_drawSprite(hunter->prim.w, hunter->scope.sprite, NULL);
    hunter->scope.mouse_pos = sfMouse_getPositionRenderWindow(hunter->prim.w);
    hunter->scope.pos.x = hunter->scope.mouse_pos.x - 75;
    hunter->scope.pos.y = hunter->scope.mouse_pos.y - 75;
    sfSprite_setPosition(hunter->scope.sprite, hunter->scope.pos);
    sfRenderWindow_display(hunter->prim.w);
}