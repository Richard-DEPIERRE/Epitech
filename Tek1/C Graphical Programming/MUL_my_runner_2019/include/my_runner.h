/*
** EPITECH PROJECT, 2019
** my_runner.h
** File description:
** h file for my_runner
*/

#ifndef MY_runner_H
#define MY_runner_H

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Window/Export.h>
#include <SFML/Graphics/Rect.h>
#include <math.h>
#include "my.h"

typedef struct text_s {
    sfText *text;
    sfFont *font;
    sfVector2f pos;
} text_t;

typedef struct prim_struct_s {
    sfRenderWindow* w;
    sfEvent event;
    sfVideoMode mode;
    sfVector2i mouse_pos;
    int Time;
    int main_menu;
    int Height;
    int Length;
    int Score;
    int Click;
    int size;
} prim_struct_t;

typedef struct clock_runner_s {
    sfClock *clock;
    sfTime time;
    float seconds;
} clock_runner_t;

typedef struct music_s {
    sfMusic* sound;
} music_t;

typedef enum BACK_s{
    BACK_1,
    BACK_2,
    BACK_3,
    BACK_4,
    PLAYER,
    PLAYER_JUMP,
    JUMP,
    TNT,
    MAIN_MENU,
    GAME_OVER,
    WIN
} BACK_t;

typedef struct game_obj_s {
    sfSprite* sprite;
    sfTexture* texture;
    sfVector2f pos;
    sfIntRect rect;
    sfVector2f scale;
    enum BACK_s type;
    int speed;
    sfVector2f pos_tnt;
} game_obj_t;

typedef struct jump_s {
    float velocity_y;
    float acceleration_y;
    float gravity;
}jump_t;

typedef struct map_s {
    char **map;
    char *str;
    int size;
    int height;
    int number_of_tnt;
    int size_map;
    sfVector2f *pos;
} map_t;

typedef struct collisions_s{
    float pos_xb;
    float pos_xp;
    float pos_yb;
    float pos_yp;
    int count;
    int count2;
} collisions_t;


typedef struct all_struct_s {
    prim_struct_t prim;
    game_obj_t *objects;
    clock_runner_t *clock_sprites;
    music_t elevator;
    music_t music;
    text_t time_text;
    text_t high_score;
    jump_t jump;
    map_t map;
    text_t score;
    int tmp;
    int jumping;
    int play;
    int pos;
    int infinite;
} all_struct_t;

void make_rect(all_struct_t *runner);

void move_rect(all_struct_t *runner);

void change_rect(all_struct_t *runner);

void main_menu_loop(all_struct_t *runner);

void change_time(all_struct_t *runner);

void move_sprite(all_struct_t *runner);

void event_loop(all_struct_t *runner);

void set_sprites(all_struct_t *runner);

void set_sprites_back(all_struct_t *runner);

void check_high_score(all_struct_t *runner);

void make_text(text_t *text, char *str, char *file);

void set_music(all_struct_t *runner);

void h_txt(int ac, char **av, int *error);

void errors(int ac, int *error);

void initialize_main_menu(all_struct_t *runner);

void initialize(all_struct_t *runner);

void game_over(all_struct_t *runner);

void main_menu(all_struct_t *runner);

void check_click(all_struct_t *runner);

void update_everything(all_struct_t *runner);

void draw_everything(all_struct_t *runner);

char *int_to_str(int nb);

void map(all_struct_t *runner, char *str);

void check_collision(all_struct_t *runner);

void jumping(all_struct_t *runner);

void game_over(all_struct_t *runner);

void game_destroy2(all_struct_t *runner);

void make_text(text_t *text, char *str, char *file);

#endif