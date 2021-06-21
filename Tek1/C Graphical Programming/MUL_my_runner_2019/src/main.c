/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** main file for my_runner
*/

#include "my_runner.h"

void game_create(all_struct_t *runner)
{
    runner->prim.Score = 0;
    runner->score.pos = (sfVector2f){830, 20};
    make_text(&runner->score, my_strcat("Score: ", \
    my_putnbr(runner->prim.Score)), "assets/amita-bold.ttf");
    runner->prim.Length = 1778;
    runner->prim.Height = 1000;
    runner->prim.w = sfRenderWindow_create(runner->prim.mode, \
    "runner beta v2.0", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(runner->prim.w, 90);
    runner->music.sound = sfMusic_createFromFile("assets/Pimped_Out_UFO.ogg");
}

void game_loop(all_struct_t *runner)
{
    for (int i = 0; i < 3; i += 1)
        runner->clock_sprites[i].clock = sfClock_create();
    sfMusic_play(runner->music.sound);
    while (sfRenderWindow_isOpen(runner->prim.w)) {
        event_loop(runner);
        update_everything(runner);
        if (runner->play == 0)
            main_menu(runner);
        else if (runner->play == 1)
            draw_everything(runner);
        else
            game_over(runner);
    }
}

void game_destroy(all_struct_t *runner)
{

    for (int i = 0; i < runner->map.size_map; i += 1) {
        sfSprite_destroy(runner->objects[i].sprite);
        sfTexture_destroy(runner->objects[i].texture);
    }
    sfRenderWindow_destroy(runner->prim.w);
}

void game_destroy2(all_struct_t *runner)
{
    for (int i = 0; i < runner->map.size_map; i += 1) {
        sfSprite_destroy(runner->objects[i].sprite);
        sfTexture_destroy(runner->objects[i].texture);
    }
}

int main(int ac, char **av)
{
    int errors = 0;
    all_struct_t runner;
    runner.prim.mode.width = 1920;
    runner.prim.mode.height = 1080;
    runner.prim.mode.bitsPerPixel = 32;
    runner.infinite = 0;

    if (ac == 3)
        if (av[2][0] == '-' && av[2][1] == 'i')
            runner.infinite = 1;
    if (av[1][0] == '-' && av[1][1] == 'h')
        h_txt(ac, av, &errors);
    else {
        map(&runner, av[1]);
        initialize(&runner);
        game_create(&runner);
        game_loop(&runner);
        game_destroy(&runner);
    }
    return errors;
}