/*
** EPITECH PROJECT, 2019
** my_ls_begin
** File description:
** begin file for my_ls
*/

#include "my_ls.h"

int initialize_folders(int ac, char **av, begin_t *begin)
{
    DIR *dir;
    if (ac == 1) {
        begin->folders = malloc(sizeof(char *) * (1));
        begin->folders[0] = NULL;
    } else {
        begin->folders = malloc(sizeof(char *) * (ac - 1));
        begin->folders[0] = NULL;
    }
    if (get_path(ac, av, begin) == 84)
        return (84);
    if (!begin->folders[0]) {
        begin->folders = malloc(sizeof(char *) * 2);
        begin->folders[0] = ".";
        begin->folders[1] = NULL;
    }
    for (int i = 0; begin->folders[i]; i += 1) {
        if (!(dir = opendir(my_strcat_mod("./", begin->folders[i]))))
            return (84);
    }
    return (0);
}

void show_basic_files(char *str, begin_t *begin)
{
    DIR *dir;
    struct dirent *sd;
    static int count = 0;
    int count2 = 0;

    if (count != 0)
        write(1, "\n", 1);
    if (str[0] != '.')
        write(1, my_strcat_mod(str, ":\n"), my_strlen4(str) + 2);
    if (!(dir = opendir(my_strcat_mod("./", str))))
        begin->error = 84;
    while ((sd = readdir(dir)) != 0 && begin->error != 84) {
        if (sd->d_name[0] != '.') {
            if (count2 != 0)
                write(1, "\n", 1);
            write(1, sd->d_name, my_strlen4(sd->d_name));
            count2 = 1;
        }
    }
    count = 1;
    write(1, "\n", 1);
}

int my_ls(int ac, char **av)
{
    begin_t begin;

    begin.error = 0;
    begin.check = 0;
    if (initialize_folders(ac, av, &begin) == 84)
        return (84);
    if (begin.folders[1] != NULL && begin.t_flag == 1) {
        put_everything_in_time_order(begin.folders, "./");
    }
    for (int i = 0; begin.folders[i]; i += 1) {
        r_flag_function(".", begin.folders[i], &begin);
    }
    if (begin.error == 84)
        return (84);
    return (0);
}