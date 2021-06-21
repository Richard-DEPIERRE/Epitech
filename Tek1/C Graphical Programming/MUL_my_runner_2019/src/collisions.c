/*
** EPITECH PROJECT, 2019
** collisions
** File description:
** file for collisions
*/

#include "my_runner.h"

void check_colision2(all_struct_t *runner, collisions_t *collide, int *check)
{
    for (int i = 0; runner->map.pos[i].x != -1; i += 1) {
        collide->pos_xb = runner->objects[i + 7].pos.x;
        collide->pos_yb = runner->objects[i + 7].pos.y;
        collide->count2 += 1;
        if ((collide->pos_xp > collide->pos_xb ||
        collide->pos_xp + 175 < collide->pos_xb) &&
        (collide->pos_xp > collide->pos_xb + 120 ||
        collide->pos_xp + 175 < collide->pos_xb + 120))
            collide->count += 1;
    }
    if (collide->count2 == collide->count) {
        runner->jumping = 740;
        runner->objects[5].pos.y = 814;
        *check = 0;
    }
}

void check3_collisions(all_struct_t *runner, collisions_t *collide, int *check)
{
    for (int i = 0; runner->map.pos[i].x != -1; i += 1) {
        collide->pos_xb = runner->objects[i + 7].pos.x;
        collide->pos_yb = runner->objects[i + 7].pos.y;
        if (((collide->pos_xp < collide->pos_xb && collide->pos_xp
        + 175 > collide->pos_xb) ||
        (collide->pos_xp < collide->pos_xb + 120 && collide->pos_xp
        + 175 > collide->pos_xb + 120)) &&
        collide->pos_yb + 100 < collide->pos_yp  + 339.5 &&
        collide->pos_yb + 200 > collide->pos_yp + 339.5 &&
        runner->objects[5].type == JUMP && check == 0){
            runner->play = 2;
        } else if (((collide->pos_xp < collide->pos_xb &&
        collide->pos_xp + 175 > collide->pos_xb) ||
        (collide->pos_xp < collide->pos_xb + 120 &&
        collide->pos_xp + 175 > collide->pos_xb + 120)) &&
        collide->pos_yb + 100 < collide->pos_yp  + 339.5
        && collide->pos_yb + 200 > collide->pos_yp + 339.5 &&
        runner->objects[5].type != JUMP && *check == 0)
            runner->play = 2;
    }
}

void check_collision(all_struct_t *runner)
{
    collisions_t collide;
    collide.pos_xb = 0;
    collide.pos_xp = runner->objects[6].pos.x;
    collide.pos_yb = 0;
    collide.pos_yp = runner->objects[6].pos.y;
    collide.count = 0;
    collide.count2 = 0;
    static int check = 0;
    static int level = 0;

    check3_collisions(runner, &collide, &check);
    check_colision2(runner, &collide, &check);
}