/*
** EPITECH PROJECT, 2020
** r_function
** File description:
** big R function file
*/

#include "my_ls.h"

void print_multiple(char *str, struct stat sb)
{
    DIR *dir;
    int total = 0;
    struct dirent *sd;

    dir = opendir(str);
    while ((sd = readdir(dir)) != 0) {
        lstat(my_strcat_mod(my_strcat_mod(str, "/"), sd->d_name), &sb);
        if (sd->d_name[0] != '.') {
            total += sb.st_blocks;
        }
    }
    write(1, "total ", 6);
    my_putnb(total/ 2);
    write(1, "\n", 1);
}

void r_flag_loop(char *src, char *str, begin_t *begin, char **table)
{
    struct stat sb;

    for (int i = 0; table[i] && begin->error != 84; i += 1) {
        if (lstat(my_strcat_mod(my_strcat_mod(my_strcat_mod(
        my_strcat_mod(src, "/"), str), "/"), table[i]),
        &sb) == -1)
            begin->error = 84;
        if (get_type(sb)[0] == 'd' && table[i][0] != '.') {
            r_flag_function(my_strcat_mod(my_strcat_mod(src, "/"), str),
            table[i], begin);
        }
    }
}

void print_r(char *src, char *str, begin_t *begin)
{
    struct stat sb;
    struct passwd *pass;
    struct group *groups;

    if (lstat(my_strcat_mod(my_strcat_mod(src, "/"), str), &sb) == -1)
        begin->error = 84;
    else if (begin->l_flag == 1) {
        print_l_flag(sb, pass, groups, str);
    } else {
        if (begin->check != 0)
            write(1, "\n", 1);
        write(1, str, my_strlen4(str));
        begin->check = 1;
    }
}

void r_flag(char *src, char *str, begin_t *begin)
{
    struct dirent *sd;
    struct stat sb;
    struct passwd *pass;
    struct group *groups;
    char **table;

    table = modifie_three(my_strcat_mod(my_strcat_mod(src, "/"), str),
    begin, sd);
    if (begin->t_flag == 1)
        put_everything_in_time_order(table, str);
    for (int i = 0; table[i]; i += 1) {
        print_r(my_strcat_mod(my_strcat_mod(src, "/"), str), table[i], begin);
    }
    if (begin->l_flag != 1)
        write(1, "\n", 1);
    if (begin->r_flag == 1) {
        begin->check = 0;
        r_flag_loop(src, str, begin, table);
    }
}

void r_flag_function(char *src, char *str, begin_t *begin)
{
    static int count = 0;
    DIR *dir;

    if (count++ != 0)
        write(1, "\n", 1);
    if (str[0] != '.' || begin->r_flag == 1)
        write(1, my_strcat_mod(my_strcat_mod(my_strcat_mod(src, "/"), str),
        ":\n"), my_strlen4(str) + 3 + my_strlen4(src));
    if (begin->l_flag == 1) {
        write(1, "total ", 6);
        dir = opendir(my_strcat_mod(my_strcat_mod(src, "/"), str));
        my_putnb(get_total(dir, str) / 2);
        write(1, "\n", 1);
    }
    r_flag(src, str, begin);
}