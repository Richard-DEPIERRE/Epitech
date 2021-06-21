/*
** EPITECH PROJECT, 2018
** day 03
** File description:
** ex00
*/

#ifndef STRING_H
#define STRING_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct string_s string_t;

typedef struct string_s
{
    char *str;
    void (*assign_s)(string_t *this, const string_t *str);
    void (*assign_c)(string_t *this, const char *s);
    void (*append_s)(string_t *this, const string_t *ap);
    void (*append_c)(string_t *this, const char *ap);
    char (*at)(const string_t *this, size_t pos);
    void (*clear)(string_t *this);
    int (*size)(const string_t *this);
    int (*compare_s)(const string_t *this, const string_t *str);
    int (*compare_c)(const string_t *this, const char *str);
    size_t (*copy)(const string_t *this, char *s, size_t n, size_t pos);
    const char *(*c_str)(const string_t *this);
    int (*empty)(const string_t *this);
    int (*to_int)(const string_t *this);
    int (*find_c)(const string_t *this, const char *str, size_t pos);
    int (*find_s)(const string_t *this, const string_t *str, size_t pos);
    void (*insert_c)(string_t *this, size_t pos, const char *str);
    void (*insert_s)(string_t *this, size_t pos, const string_t *str);
    string_t **(*split_s)(const string_t *this, char separator);
    char **(*split_c)(const string_t *this, char separator);
    void (*join_c)(string_t *this, char delim, const char * const * tab);
    void (*join_s)(string_t *this, char delim, const string_t * const * tab);
    void (*print)(const string_t *this);
    string_t *(*substr)(const string_t *this, int offset, int length);
} string_t;

void string_init(string_t *this, const char *s);
void string_destroy(string_t *this);
void assign_s(string_t *this, const string_t *str);
void assign_c(string_t *this, const char *s);
void append_s(string_t *this, const string_t *ap);
void append_c(string_t *this, const char *ap);
char at(const string_t *this, size_t pos);
void clear(string_t *this);
int size(const string_t *this);
int compare_s(const string_t *this, const string_t *str);
int compare_c(const string_t *this, const char *str);
size_t copy(const string_t *this, char *s, size_t n, size_t pos);
const char *c_str(const string_t *this);
int empty(const string_t *this);
int find_c(const string_t *this, const char *str, size_t pos);
int find_s(const string_t *this, const string_t *str, size_t pos);
void insert_c(string_t *this, size_t pos, const char *str);
void insert_s(string_t *this, size_t pos, const string_t *str);
string_t **split_s(const string_t *this, char separator);
char **split_c(const string_t *this, char separator);
void join_c(string_t *this, char delim, const char * const * tab);
void join_s(string_t *this, char delim, const string_t * const * tab);
int to_int(const string_t *this);
string_t *substr(const string_t *this, int offset, int length);
void print(const string_t *this);

#endif