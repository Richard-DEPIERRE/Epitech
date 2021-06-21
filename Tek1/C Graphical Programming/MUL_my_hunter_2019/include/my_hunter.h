/*
** EPITECH PROJECT, 2019
** my_hunter.h
** File description:
** h file for my_hunter
*/

#ifndef MY_HUNTER_H
#define MY_HUNTER_H

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Window/Export.h>
#include <SFML/Graphics/Rect.h>
#include <math.h>
#include "my.h"

typedef struct prim_struct_s {
    sfClock *clock;
    sfClock *clock2;
    sfRenderWindow* w;
    sfEvent event;
    sfMusic* music;
    sfMusic* elevator;
    sfTime time;
    sfTime time2;
    sfVideoMode mode;
    float seconds;
    float seconds2;
    int Height;
    int Length;
    int Score;
    int Time;
    int main;
    int game_over;
    int main_menu;
    int click;
} prim_struct_t;

typedef struct sprite_s {
    sfSprite* sprite;
    sfTexture* texture;
    sfVector2f pos;
    sfIntRect rect;
    sfVector2f scale;
    sfVector2i mouse_pos;
    char *filename;
    int tmp;
    float x;
    int y_range;
}sprite_t;

typedef struct text_s {
    sfText *text;
    sfFont *font;
    sfVector2f pos;
} text_t;

typedef struct all_struct_s {
    prim_struct_t prim;
    sprite_t ufo;
    sprite_t ufo2;
    sprite_t back;
    sprite_t main_menu;
    sprite_t game_over;
    sprite_t scope;
    sprite_t pause;
    text_t score;
    text_t high_score;
    text_t time;
} all_struct_t;

void make_rect(all_struct_t *hunter);

void change_rect(all_struct_t *hunter);

void main_menu_loop(all_struct_t *hunter);

void change_time(all_struct_t *hunter);

void move_sprite(all_struct_t *hunter);

void event_loop(all_struct_t *hunter);

void set_sprites(all_struct_t *hunter);

void set_sprites_back(all_struct_t *hunter);

void check_high_score(all_struct_t *hunter);

void initialize_back(sprite_t *back);

void initialize_ufo(sprite_t *ufo);

void draw_everything(all_struct_t *hunter);

void get_pos(prim_struct_t *prim_struct, sprite_t *sprite);

void make_my_sprites(sprite_t *back, char *str);

void make_text(text_t *text, char *str, char *file);

void set_music(all_struct_t *hunter);

void h_txt(int ac, char **av, int *error);

void errors(int ac, int *error);

void initialize_main_menu(all_struct_t *hunter);

void initialize(all_struct_t *hunter);

void game_over(all_struct_t *hunter);

void main_menu(all_struct_t *hunter);

void check_click(all_struct_t *hunter);

#endif