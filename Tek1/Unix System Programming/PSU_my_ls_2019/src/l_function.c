/*
** EPITECH PROJECT, 2020
** l_function
** File description:
** function for -l
*/

#include "my_ls.h"

char *get_permissions(struct stat sb)
{
    char *str = malloc(sizeof(char) * 10);
    int i = 0;

    str[i++] = (sb.st_mode & S_IRUSR) ? 'r' : '-';
    str[i++] = (sb.st_mode & S_IWUSR) ? 'w' : '-';
    str[i++] = (sb.st_mode & S_IXUSR) ? 'x' : '-';
    str[i++] = (sb.st_mode & S_IRUSR) ? 'r' : '-';
    str[i++] = (sb.st_mode & S_IWUSR) ? 'w' : '-';
    str[i++] = (sb.st_mode & S_IXUSR) ? 'x' : '-';
    str[i++] = (sb.st_mode & S_IRUSR) ? 'r' : '-';
    str[i++] = (sb.st_mode & S_IWUSR) ? 'w' : '-';
    str[i++] = (sb.st_mode & S_IXUSR) ? 'x' : '-';
    str[i] = '\0';
    return (str);
}

char *get_type(struct stat sb)
{
    char *str = malloc(sizeof(char) * 2);

    str[1] = '\0';
    switch (sb.st_mode & __S_IFMT) {
    case __S_IFDIR:
        str[0] = 'd';
        break;
    case __S_IFLNK:
        str[0] = 'l';
        break;
    case __S_IFREG:
        str[0] = '-';
        break;
    case __S_IFCHR:
        str[0] = 'c';
        break;
    }
    return (str);
}

int get_total(DIR *dir, char *str)
{
    int total = 0;
    struct dirent *sd;
    struct stat sb;

    while ((sd = readdir(dir)) != 0) {
        lstat(my_strcat_mod(my_strcat_mod(str, "/"),
        sd->d_name), &sb);
        if (sd->d_name[0] != '.') {
            total += sb.st_blocks;
        }
    }
    return (total);
}