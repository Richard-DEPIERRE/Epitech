/*
** EPITECH PROJECT, 2019
** my
** File description:
** my
*/

#ifndef DRAWING
#define DRAWING

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <grp.h>
#include <dirent.h>
#include <pwd.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>

typedef struct __attribute__((packed)) point_s
{
    unsigned int x;
    unsigned int y;
} point_t;

void draw_square(uint32_t **img, const point_t *origin,
size_t size, uint32_t color);

#endif