/*
** EPITECH PROJECT, 2021
** main.cpp
** File description:
** main
*/

#ifndef EX00_H
#define EX00_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cthulhu_s {
    int m_power;
    char *m_name;
} cthulhu_t;

typedef struct koala_s {
    char m_is_a_legend;
    cthulhu_t m_parent;
} koala_t;

static void cthulhu_initializer(cthulhu_t *this);
cthulhu_t *new_cthulhu();
void print_power(cthulhu_t *this);
void attack(cthulhu_t *this);
void sleeping(cthulhu_t *this);
static void koala_initializer(koala_t *this, char *_name, char _is_A_Legend);
koala_t *new_koala(char *name, char is_a_legend);
void eat(koala_t *this);

#endif
