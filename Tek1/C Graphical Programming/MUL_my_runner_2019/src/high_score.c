/*
** EPITECH PROJECT, 2019
** high_score
** File description:
** file for highest score
*/

#include "my_runner.h"

void check_high_score(all_struct_t *runner)
{
    int fd = 0;
    int size = 6;
    char *buffer;

    fd = open("images/high_score.txt", O_RDWR);
    buffer = malloc(sizeof(char) * (size + 3));
    read(fd, buffer, size);
    if (runner->prim.Score > my_getnbr(buffer))
        write(fd, buffer, my_strlen(buffer));
}

void set_music(all_struct_t *runner)
{
    if (runner->prim.Click == -1) {
        sfMusic_setVolume(runner->music.sound, (float)(0));
        sfMusic_setVolume(runner->elevator.sound, (float)(100));
    }
    if (runner->prim.Click == 1) {
        sfMusic_setVolume(runner->music.sound, (float)(100));
        sfMusic_setVolume(runner->elevator.sound, (float)(0));
    }
}