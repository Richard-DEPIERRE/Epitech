/*
** EPITECH PROJECT, 2020
** funct4
** File description:
** 4 file for functions
*/

#include "my_ls.h"

char **sort_array(char **array, long long *order)
{
    char *tmp;
    long long temp;

    for (int i = 0; array[i]; i += 1)
        for (int j = i + 1; array[j]; j += 1) {
            if (order[i] < order[j]) {
                tmp = my_strcpy2(array[i]);
                array[i] = my_strcpy2(array[j]);
                array[j] = my_strcpy2(tmp);
                temp = order[i];
                order[i] = order[j];
                order[j] = temp;
            }
        }
    return (array);
}

void print_l_flag(struct stat sb, struct passwd *pass,
struct group *groups, char *str)
{
    write(1, get_type(sb), 1);
    write(1, get_permissions(sb), 9);
    write(1, " ", 1);
    my_putlong((long)sb.st_nlink);
    write(1, " ", 1);
    pass = getpwuid(sb.st_uid);
    write(1, pass->pw_name, my_strlen4(pass->pw_name));
    write(1, " ", 1);
    groups = getgrgid(sb.st_gid);
    write (1, groups->gr_name, my_strlen4(groups->gr_name));
    write(1, " ", 1);
    my_putlonglong((long long)sb.st_size);
    write(1, " ", 1);
    for (int j = 4; j < 16; j += 1)
        write(1, &(ctime(&sb.st_mtime))[j], 1);
    write(1, " ", 1);
    write(1, str, my_strlen4(str));
    write(1, "\n", 1);
}

void print_function_l(struct stat sb, struct passwd *pass,
struct group *groups, struct dirent *sd)
{
    write(1, get_type(sb), 1);
    write(1, get_permissions(sb), 9);
    write(1, " ", 1);
    my_putlong((long)sb.st_nlink);
    write(1, " ", 1);
    pass = getpwuid(sb.st_uid);
    write(1, pass->pw_name, my_strlen4(pass->pw_name));
    write(1, " ", 1);
    groups = getgrgid(sb.st_gid);
    write (1, groups->gr_name, my_strlen4(groups->gr_name));
    write(1, " ", 1);
    my_putlonglong((long long)sb.st_size);
    write(1, " ", 1);
    for (int j = 4; j < 16; j += 1)
        write(1, &(ctime(&sb.st_mtime))[j], 1);
    write(1, " ", 1);
    write(1, sd->d_name, my_strlen4(sd->d_name));
    write(1, "\n", 1);
}

char **modifie_three(char *str, begin_t *begin, struct dirent *sd)
{
    char **table;
    DIR *dir;
    int i = 0;

    if (!(dir = opendir(my_strcat_mod("./", str))))
        begin->error = 84;
    if (begin->error != 84)
        table = malloc(sizeof(char *) * (count_dir(dir, str, begin) + 1));
    if (!(dir = opendir(my_strcat_mod("./", str))))
        begin->error = 84;
    while ((sd = readdir(dir)) != 0 && begin->error != 84) {
        if (sd->d_name[0] != '.') {
            table[i++] = my_strcpy2(sd->d_name);
        }
    }
    table[i] = NULL;
    return (table);
}