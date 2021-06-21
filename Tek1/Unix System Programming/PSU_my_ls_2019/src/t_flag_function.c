/*
** EPITECH PROJECT, 2020
** t_flag_function
** File description:
** functions for t flag
*/

#include "my_ls.h"

int count_dir(DIR *dir, char *str, begin_t *begin)
{
    int total = 0;
    struct dirent *sd;
    struct stat sb;

    while ((sd = readdir(dir)) != 0 && begin->error != 84) {
        if (lstat(my_strcat_mod(my_strcat_mod(str, "/"),
        sd->d_name), &sb) == -1)
            begin->error = 84;
        if (sd->d_name[0] != '.') {
            total += 1;
        }
    }
    return (total);
}