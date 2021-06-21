/*
** EPITECH PROJECT, 2019
** main_menu
** File description:
** file for main menu
*/

#include "my_hunter.h"

void main_menu(all_struct_t *hunter)
{
    sfRenderWindow_clear(hunter->prim.w, sfBlack);
    sfRenderWindow_drawSprite(hunter->prim.w, hunter->main_menu.sprite, NULL);
    sfRenderWindow_drawSprite(hunter->prim.w, hunter->scope.sprite, NULL);
    hunter->scope.mouse_pos = sfMouse_getPositionRenderWindow(hunter->prim.w);
    hunter->scope.pos.x = hunter->scope.mouse_pos.x - 75;
    hunter->scope.pos.y = hunter->scope.mouse_pos.y - 75;
    sfSprite_setPosition(hunter->scope.sprite, hunter->scope.pos);
    sfRenderWindow_display(hunter->prim.w);
}

void check_click(all_struct_t *hunter)
{
    if (hunter->ufo.mouse_pos.x >=  1170 && hunter->ufo.mouse_pos.x <= 1259)
        if (hunter->ufo.mouse_pos.y >= 875 && hunter->ufo.mouse_pos.y <= 966)
            sfRenderWindow_close(hunter->prim.w);
    if (hunter->ufo.mouse_pos.x >=  1280 && hunter->ufo.mouse_pos.x <= 1384)
        if (hunter->ufo.mouse_pos.y >= 875 && hunter->ufo.mouse_pos.y <= 966)
            hunter->prim.click *= (-1);
}

void main_menu_loop(all_struct_t *hunter)
{
    hunter->main_menu.mouse_pos = \
    sfMouse_getPositionRenderWindow(hunter->prim.w);
    if (hunter->main_menu.mouse_pos.x >=  340 && \
    hunter->main_menu.mouse_pos.x <= 1055)
        if (hunter->main_menu.mouse_pos.y >= 780 && \
        hunter->main_menu.mouse_pos.y <= 935)
            hunter->prim.main_menu = 1;
    if (hunter->main_menu.mouse_pos.x >=  1270 && \
    hunter->main_menu.mouse_pos.x <= 1355)
        if (hunter->main_menu.mouse_pos.y >= 940 && \
        hunter->main_menu.mouse_pos.y <= 1035)
            sfRenderWindow_close(hunter->prim.w);
}