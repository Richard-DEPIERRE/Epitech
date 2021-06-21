/*
** EPITECH PROJECT, 2019
** high_score
** File description:
** file for highest score
*/

#include "my_hunter.h"

void check_high_score(all_struct_t *hunter)
{
    int fd = 0;
    int size = 6;
    char *buffer;

    fd = open("images/high_score.txt", O_RDWR);
    buffer = malloc(sizeof(char) * (size + 3));
    read(fd, buffer, size);
    if (hunter->prim.Score > my_getnbr(buffer))
        write(fd, buffer, my_strlen(buffer));
}

void set_music(all_struct_t *hunter)
{
    if (hunter->prim.click == -1) {
        sfMusic_setVolume(hunter->prim.music, (float)(0));
        sfMusic_setVolume(hunter->prim.elevator, (float)(100));
    }
    if (hunter->prim.click == 1) {
        sfMusic_setVolume(hunter->prim.music, (float)(100));
        sfMusic_setVolume(hunter->prim.elevator, (float)(0));
    }
}