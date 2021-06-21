/*
** EPITECH PROJECT, 2019
** my_hunter_3
** File description:
** my hunter file
*/

#include "my_hunter.h"

void initialize_scope(sprite_t *scope)
{
    scope->rect.left = 0;
    scope->rect.top = 0;
    scope->rect.width = 750;
    scope->rect.height = 750;
    scope->pos.x = 200;
    scope->pos.y = 33;
    scope->scale = (sfVector2f){0.2, 0.2};
}

void initialize_main_menu(all_struct_t *hunter)
{
    hunter->main_menu.rect.left = 0;
    hunter->main_menu.rect.top = 0;
    hunter->main_menu.rect.width = 1400;
    hunter->main_menu.rect.height = 1067;
    hunter->main_menu.pos.x = 0;
    hunter->main_menu.pos.y = 0;
    hunter->main_menu.scale = (sfVector2f){1, 1};
}

void initialize_back(sprite_t *back)
{
    back->rect.left = 0;
    back->rect.top = 0;
    back->rect.width = 1400;
    back->rect.height = 1067;
    back->pos.x = 0;
    back->pos.y = 0;
    back->scale = (sfVector2f){1, 1};
}

void initialize_ufo(sprite_t *ufo)
{
    ufo->rect.left = 0;
    ufo->rect.top = 0;
    ufo->rect.width = 376;
    ufo->rect.height = 248;
    ufo->pos.x = 200;
    ufo->pos.y = 200;
    ufo->scale = (sfVector2f){0.5, 0.5};
    ufo->tmp = 0;
    ufo->y_range = 0;
}

void initialize(all_struct_t *hunter)
{
    initialize_ufo(&hunter->ufo);
    initialize_ufo(&hunter->ufo2);
    initialize_back(&hunter->back);
    initialize_back(&hunter->game_over);
    initialize_back(&hunter->main_menu);
    initialize_main_menu(hunter);
    initialize_scope(&hunter->scope);
    initialize_scope(&hunter->pause);
    hunter->score.pos = (sfVector2f){20, 995};
    hunter->high_score.pos = (sfVector2f){20, 10};
    hunter->time.pos = (sfVector2f){670, 10};
    hunter->prim.click = 1;
    hunter->prim.Score = 0;
}