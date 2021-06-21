/*
** EPITECH PROJECT, 2019
** my_runner_1
** File description:
** file for my_runner
*/

#include "my_runner.h"

void move_rect(all_struct_t *runner)
{
    if (runner->objects[5].rect.left < 343)
        runner->objects[5].rect.left += 68;
    if (runner->objects[5].rect.left >= 343)
        runner->objects[5].rect.left = 0;
    if (runner->objects[5].type == JUMP) {
        if (runner->objects[6].rect.left < 150)
            runner->objects[6].rect.left += 50;
        if (runner->objects[6].rect.left >= 150)
            runner->objects[6].rect.left = 0;
    } else {
        runner->objects[6].rect.left = 0;
    }
}

void jumping(all_struct_t *runner)
{
    runner->jump.velocity_y -= runner->jump.gravity;
    runner->objects[6].pos.y -= runner->jump.velocity_y;
}

void update3(all_struct_t * runner)
{
    if (runner->objects[6].pos.y > runner->jumping && \
    runner->objects[5].type == JUMP) {
        runner->objects[5].type = PLAYER;
        runner->objects[6].pos.y = runner->jumping;
        runner->jump.velocity_y = 50;
    }
    for (int i = 0; i < 5; i += 1)
        sfSprite_setPosition(runner->objects[i].sprite, runner->objects[i].pos);
    sfSprite_setPosition(runner->objects[6].sprite, runner->objects[6].pos);
    sfSprite_setPosition(runner->objects[5].sprite, runner->objects[5].pos);
    for (int i = 0; runner->map.pos[i].x != -1; i += 1) {
        sfSprite_setPosition(runner->objects[i + 7].sprite, \
        runner->objects[i + 7].pos);
    }
    sfSprite_setPosition(runner->objects[runner->pos].sprite, \
    runner->objects[runner->pos].pos);
    sfText_setString(runner->score.text, \
    my_strcat("Score: ", my_putnbr(runner->prim.Score)));
}

void update2(all_struct_t *runner, int *count)
{
    if (runner->clock_sprites[0].seconds > 0.019) {
        if (runner->play == 1) {
            if (runner->objects[5].type == JUMP)
                jumping(runner);
            check_collision(runner);
            for (; runner->map.pos[*count].x != -1; *count += 1) {
                runner->objects[*count + 7].pos.x -= \
                runner->objects[*count + 7].speed + 5;
            }
            runner->prim.Score += 1;
        }
        if (runner->play == 1)
            runner->objects[runner->pos].pos.x -= \
            runner->objects[runner->pos].speed + 5;
        for (int i = 0; i < 5; i += 1)
            runner->objects[i].pos.x -= runner->objects[i].speed + 5;
        change_rect(runner);
    }
}

void update_everything(all_struct_t *runner)
{
    int count = 0;
    for (int i = 0; i < 3; i += 1) {
        runner->clock_sprites[i].time = sfClock_getElapsedTime\
        (runner->clock_sprites[i].clock);
        runner->clock_sprites[i].seconds = \
        runner->clock_sprites[i].time.microseconds / 1000000.0;
    }
    update2(runner, &count);
    if (runner->clock_sprites[0].seconds > 0.05 && runner->play == 1) {
        sfSprite_setTextureRect(runner->objects[5].sprite, \
        runner->objects[5].rect);
        sfClock_restart(runner->clock_sprites[0].clock);
    }
    update3(runner);
}