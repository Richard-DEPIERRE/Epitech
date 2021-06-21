/*
** EPITECH PROJECT, 2019
** my_hunter_1
** File description:
** main file for my_hunter
*/

#include "my_hunter.h"

void game_create(all_struct_t *hunter)
{
    make_my_sprites(&hunter->ufo, "images/ufo_green.png");
    make_my_sprites(&hunter->ufo2, "images/ufo_green.png");
    make_my_sprites(&hunter->back, "images/night_background1.png");
    make_my_sprites(&hunter->scope, "images/scope.png");
    make_my_sprites(&hunter->game_over, "images/game_over.jpg");
    make_my_sprites(&hunter->main_menu, "images/menu-background.jpg");
    make_my_sprites(&hunter->pause, "images/pause.png");
    make_text(&hunter->score, my_strcat("Score: ", \
    my_putnbr(hunter->prim.Score)), "images/amita-bold.ttf");
    make_text(&hunter->high_score, "Highest-score : 0", \
    "images/amita-bold.ttf");
    make_text(&hunter->time, "Time : 60", "images/amita-bold.ttf");
    hunter->prim.Length = 1400;
    hunter->prim.Height = 1067;
    hunter->prim.w = sfRenderWindow_create(hunter->prim.mode, \
    "UFO_HUNTER beta v0.2", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(hunter->prim.w, 60);
    hunter->prim.music = sfMusic_createFromFile("sounds/Pimped_Out_UFO.ogg");
    hunter->prim.elevator = sfMusic_createFromFile("sounds/Elevator_Music.ogg");
    hunter->prim.Score = 0;
}

void game_loop(all_struct_t *hunter)
{
    hunter->prim.main = 0;
    sfMusic_play(hunter->prim.music);
    sfMusic_play(hunter->prim.elevator);
    hunter->prim.clock = sfClock_create();
    hunter->prim.clock2 = sfClock_create();
    hunter->prim.Time = 60;
    hunter->prim.main_menu = 0;
    while (sfRenderWindow_isOpen(hunter->prim.w)) {
        sfRenderWindow_setMouseCursorVisible(hunter->prim.w, sfFalse);
        event_loop(hunter);
        set_music(hunter);
        if (hunter->prim.Time < 0)
            game_over(hunter);
        else if (hunter->prim.main_menu == 0)
            main_menu(hunter);
        else
            draw_everything(hunter);
    }
}

void game_destroy(all_struct_t *hunter)
{
    sfMusic_destroy(hunter->prim.elevator);
    sfMusic_destroy(hunter->prim.music);
    sfSprite_destroy(hunter->ufo.sprite);
    sfTexture_destroy(hunter->ufo.texture);
    sfSprite_destroy(hunter->ufo2.sprite);
    sfTexture_destroy(hunter->ufo2.texture);
    sfSprite_destroy(hunter->back.sprite);
    sfTexture_destroy(hunter->back.texture);
    sfSprite_destroy(hunter->scope.sprite);
    sfTexture_destroy(hunter->scope.texture);
    sfText_destroy(hunter->score.text);
    sfText_destroy(hunter->high_score.text);
    sfText_destroy(hunter->time.text);
    sfRenderWindow_destroy(hunter->prim.w);
}

int main(int ac, char **av)
{
    int errors = 0;
    all_struct_t hunter;
    hunter.prim.mode.width = 1400;
    hunter.prim.mode.height = 1067;
    hunter.prim.mode.bitsPerPixel = 32;

    if (ac == 1) {
        initialize(&hunter);
        game_create(&hunter);
        game_loop(&hunter);
        game_destroy(&hunter);
    } else {
        h_txt(ac, av, &errors);
    }
    return errors;
}