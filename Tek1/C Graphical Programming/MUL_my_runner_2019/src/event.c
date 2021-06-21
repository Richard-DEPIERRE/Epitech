/*
** EPITECH PROJECT, 2019
** my_runner_5
** File description:
** event file
*/

#include "my_runner.h"

void check_first_loop(all_struct_t *runner)
{
    if (runner->prim.mouse_pos.x >=  610 &&
    runner->prim.mouse_pos.x <= 1220)
        if (runner->prim.mouse_pos.y >= 305 &&
        runner->prim.mouse_pos.y <= 450)
            runner->play = 1;
    if (runner->prim.mouse_pos.x >=  680 &&
    runner->prim.mouse_pos.x <= 1130)
        if (runner->prim.mouse_pos.y >= 580 &&
        runner->prim.mouse_pos.y <= 742)
            sfRenderWindow_close(runner->prim.w);
}

void event2(all_struct_t *runner)
{
    if (runner->prim.event.type == sfEvtMouseButtonPressed)
        check_first_loop(runner);
}

void event_loop(all_struct_t *runner)
{
    while (sfRenderWindow_pollEvent(runner->prim.w, &runner->prim.event)) {
        runner->prim.mouse_pos = \
        sfMouse_getPositionRenderWindow(runner->prim.w);
        if (runner->prim.event.type == sfEvtClosed)
            sfRenderWindow_close(runner->prim.w);
        if (runner->prim.event.key.code == sfKeyEscape)
            sfRenderWindow_close(runner->prim.w);
        if (runner->prim.event.key.code == sfKeySpace && \
        runner->objects[5].type != JUMP && runner->play != 2)
            runner->objects[5].type = JUMP;
        event2(runner);
    }
}