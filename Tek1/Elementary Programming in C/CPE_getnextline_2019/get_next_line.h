/*
** EPITECH PROJECT, 2019
** getnextline
** File description:
** header for getnextline
*/

#ifndef GETNEXT
#define GETNEXT
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <fcntl.h>

#ifndef READ_SIZE
#define READ_SIZE 5
#endif

typedef struct get_line_s {
    char *res;
    char *str;
    int a;
    int i;
    int j;
} get_line_t;

char *get_next_line(int fd);

#endif /* !GETNEXT */