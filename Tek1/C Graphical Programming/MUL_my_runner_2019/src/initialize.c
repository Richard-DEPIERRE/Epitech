/*
** EPITECH PROJECT, 2019
** my_runner_3
** File description:
** my runner file
*/

#include "my_runner.h"

game_obj_t create_object(char *filepath, sfVector2f pos, sfIntRect rect, \
enum BACK_s type)
{
    game_obj_t object;

    object.texture = sfTexture_createFromFile(filepath, NULL);
    object.sprite = sfSprite_create();
    sfSprite_setPosition(object.sprite, pos);
    sfSprite_setTexture(object.sprite, object.texture, sfTrue);
    sfSprite_setTextureRect(object.sprite, rect);
    object.rect = rect;
    object.pos = pos;
    object.type = type;
    if (type < PLAYER)
        object.speed = type * 2;
    if (type >= PLAYER && type < TNT)
        sfSprite_setScale(object.sprite, (sfVector2f){3.5, 3.5});
    if (type == TNT || type == MAIN_MENU || type == GAME_OVER)
        object.speed = BACK_4 + 2;
    return (object);
}

void initialize_type(all_struct_t *runner)
{
    runner->jumping = 740;
    runner->play = 0;
    runner->clock_sprites = malloc(sizeof(*runner->clock_sprites) * 3);
    runner->objects = malloc(sizeof(*runner->objects) * runner->map.size_map);
    runner->jump.gravity = 2;
    runner->jump.velocity_y = 50;
    runner->objects[0].type = BACK_1;
    runner->objects[1].type = BACK_1;
    for (int i = 0; i < 3; i += 1)
        runner->objects[i + 2].type = BACK_2 + i;
}

void initialise(all_struct_t *runner)
{
    int j = 0;
    for (; runner->map.pos[j].x != -1; j += 1)
        runner->objects[7 + j] = create_object( "assets/spikes.png", \
        runner->map.pos[j], (sfIntRect){0, 0, 120, 200}, TNT);
    j += 7;
    runner->pos = j;
    runner->objects[j++] = create_object("assets/start.png", \
    (sfVector2f){209, 174.5}, (sfIntRect){0, 0, 1500, 671}, MAIN_MENU);
    runner->objects[j++] = create_object("assets/game_over.png", \
    (sfVector2f){270, 330}, (sfIntRect){0, 0, 1480, 229}, GAME_OVER);
    runner->objects[j] = create_object("assets/win.png", \
    (sfVector2f){270, 330}, (sfIntRect){0, 0, 440, 290}, WIN);
}

void initialize(all_struct_t *runner)
{
    initialize_type(runner);
    for (int i = 0; i < 4; i += 1) {
        runner->objects[i] = create_object( my_strcat("assets/", \
        my_strcat(int_to_str(i), "_F.png")), (sfVector2f){0, 0}, \
        (sfIntRect){0, 0, 3840, 1080}, runner->objects[i].type);
    }
    runner->objects[4] = create_object( my_strcat("assets/", \
        my_strcat(int_to_str(4), "_F.png")), (sfVector2f){0, 100}, \
        (sfIntRect){0, 0, 3840, 1080}, runner->objects[4].type);
    runner->objects[5] = create_object( "assets/player.png", \
    (sfVector2f){60, 814}, (sfIntRect){0, 0, 68, 76}, PLAYER);
    runner->objects[6] = create_object( "assets/player_jump.png",
    (sfVector2f){62, 740}, (sfIntRect){0, 0, 50, 97}, PLAYER_JUMP);
    initialise(runner);
}

void make_text(text_t *text, char *str, char *file)
{
    text->font = sfFont_createFromFile(file);
    text->text = sfText_create();
    sfText_setString(text->text, str);
    sfText_setFont(text->text, text->font);
    sfText_setCharacterSize(text->text, 100);
    sfText_setPosition(text->text, text->pos);
    sfText_setColor(text->text, sfBlack);
}