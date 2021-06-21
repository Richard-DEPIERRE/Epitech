/*
** EPITECH PROJECT, 2019
** my_hunter_4
** File description:
** 4th file for my_hunter
*/

#include "my_hunter.h"

void make_text(text_t *text, char *str, char *file)
{
    text->font = sfFont_createFromFile(file);
    text->text = sfText_create();
    sfText_setString(text->text, str);
    sfText_setFont(text->text, text->font);
    sfText_setCharacterSize(text->text, 50);
    sfText_setPosition(text->text, text->pos);
}

void make_my_sprites(sprite_t *back, char *str)
{
    back->texture = sfTexture_createFromFile(str, NULL);
    back->sprite = sfSprite_create();
    sfSprite_setPosition(back->sprite, back->pos);
    sfSprite_setTexture(back->sprite, back->texture, sfTrue);
    sfSprite_setTextureRect(back->sprite, back->rect);
    sfSprite_setScale(back->sprite, back->scale);
}

void move_sprite(all_struct_t *hunter)
{
    if (hunter->prim.seconds > 0.01) {
        hunter->ufo.pos.x = (hunter->prim.Length/2 - 200) + \
        (hunter->prim.Length/2 + 200) * sin(hunter->ufo.x);
        hunter->ufo.pos.y = (hunter->prim.Height / 4) + (hunter->prim.Height \
        / 4 + 100) * cos(hunter->ufo.x) * sin(hunter->ufo.x);
        hunter->ufo2.pos.x = (hunter->prim.Length/2 - 200) - \
        (hunter->prim.Length/2 + 200) * sin(hunter->ufo2.x);
        hunter->ufo2.pos.y = (hunter->prim.Height / 4) + (hunter->prim.Height \
        / 4 + 100) * cos(hunter->ufo2.x) * sin(hunter->ufo2.x);
    }
}

void set_sprites(all_struct_t *hunter)
{
    sfSprite_setTextureRect(hunter->ufo.sprite, hunter->ufo.rect);
    sfSprite_setTextureRect(hunter->ufo2.sprite, hunter->ufo2.rect);
    hunter->ufo.x += 0.02f;
    hunter->ufo2.x += 0.02f;
    hunter->scope.mouse_pos = sfMouse_getPositionRenderWindow(hunter->prim.w);
    hunter->scope.pos.x = hunter->scope.mouse_pos.x - 75;
    hunter->scope.pos.y = hunter->scope.mouse_pos.y - 75;
    move_sprite(hunter);
    change_rect(hunter);
    change_time(hunter);
    sfSprite_setPosition(hunter->scope.sprite, hunter->scope.pos);
    sfSprite_setPosition(hunter->ufo.sprite, hunter->ufo.pos);
    sfSprite_setPosition(hunter->ufo2.sprite, hunter->ufo2.pos);
}