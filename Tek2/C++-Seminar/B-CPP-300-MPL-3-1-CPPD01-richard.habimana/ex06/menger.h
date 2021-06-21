/*
** EPITECH PROJECT, 2019
** my
** File description:
** my
*/

#ifndef MENGER
#define MENGER

#include <stdlib.h>
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

typedef struct coordinate_s {
    int x;
    int y;
} coordinate_t;

void meng(int size, int level, coordinate_t points, unsigned int **img);
int my_getnbr(char const *str);
int check_errors(int ac, char **av);
void initialize_image(size_t size, unsigned int *buffer, unsigned int **img);
void write_bmp_header(int fd, size_t size);
void write_bmp_info_header(int fd, size_t size);

#endif