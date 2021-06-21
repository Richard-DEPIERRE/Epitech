/*
** EPITECH PROJECT, 2021
** main.cpp
** File description:
** main
*/

#include "ex00.h"

static void cthulhu_initializer(cthulhu_t *this)
{
    this->m_power = 42;
    this->m_name = calloc(8, sizeof(char));
    strcpy(this->m_name, "Cthulhu");
}

cthulhu_t *new_cthulhu()
{
    cthulhu_t *new = malloc(sizeof(*new));

    printf("----\nBuilding Cthulhu\n");
    cthulhu_initializer(new);
    return (new);
}

void print_power(cthulhu_t *this)
{
    printf("Power => %d\n", this->m_power);
}

void attack(cthulhu_t *this)
{
    if (this->m_power < 42) {
        printf("%s can't attack, he doesn't have enough power\n", this->m_name);
        return;
    }
    this->m_power -= 42;
    printf("%s attacks and destroys the city\n", this->m_name);
}

void sleeping(cthulhu_t *this)
{
    printf("%s sleeps\n", this->m_name);
    this->m_power += 42000;
}

static void koala_initializer(koala_t *this, char *_name, char _is_A_Legend)
{
    this->m_is_a_legend = _is_A_Legend;
    this->m_parent = *(new_cthulhu());
    free(this->m_parent.m_name);
    this->m_parent.m_name = calloc(strlen(_name), sizeof(char));
    if (_is_A_Legend == 0)
        this->m_parent.m_power = 0;
    strcpy(this->m_parent.m_name, _name);
}


koala_t *new_koala(char *name, char is_a_legend)
{
    koala_t *new = malloc(sizeof(*new));

    koala_initializer(new, name, is_a_legend);
    printf("Building %s\n", new->m_parent.m_name);
    return (new);
}

void eat(koala_t *this)
{
    printf("%s eats\n", this->m_parent.m_name);
    this->m_parent.m_power += 42;
}