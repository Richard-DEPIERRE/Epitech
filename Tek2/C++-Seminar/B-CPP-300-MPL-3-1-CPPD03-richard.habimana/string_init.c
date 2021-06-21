/*
** EPITECH PROJECT, 2021
** ex04
** File description:
** add
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "string.h"

void string_init_two(string_t *this)
{
    this->compare_s = &compare_s;
    this->compare_c = &compare_c;
    this->copy = &copy;
    this->c_str = &c_str;
    this->empty = &empty;
    this->find_c = &find_c;
    this->find_s = &find_s;
    this->insert_c = &insert_c;
    this->insert_s = &insert_s;
    this->split_c = &split_c;
    this->split_s = &split_s;
    this->join_c = &join_c;
    this->join_s = &join_s;
    this->to_int = &to_int;
    this->print = &print;
}

void string_init(string_t *this, const char *s)
{
    if (!s)
        this->str = NULL;
    else {
        this->str = malloc(sizeof(char) * (strlen(s) + 1));
        for (size_t i = 0; i < strlen(s); i++)
            this->str[i] = s[i];
        this->str[strlen(s)] = '\0';
    }
    this->assign_s = &assign_s;
    this->assign_c = &assign_c;
    this->append_s = &append_s;
    this->append_c = &append_c;
    this->at = &at;
    this->clear = &clear;
    this->size = &size;
    this->substr = &substr;
    string_init_two(this);
}

void string_destroy(string_t *this)
{
    free(this->str);
}