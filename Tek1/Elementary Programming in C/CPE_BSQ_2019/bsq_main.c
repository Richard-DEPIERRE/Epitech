/*
** EPITECH PROJECT, 2019
** bsq_main
** File description:
** main for bsq
*/
#include "include/my.h"

int error_bsq(int ac)
{
    if (ac > 2) {
        write(2, "too many arguments\n", 20);
        return 84;
    } else if (ac == 1) {
        write(2, "not enough arguments\n", 22);
        return 84;
    }
    return 0;
}

int fs_understand_return_of_read(int fd, int size)
{
    char *buffer = malloc(sizeof(char) * (size - 1));
    int a = read(fd, buffer, size);
    int error = 0;

    if (a == -1) {
        write(2, "read failed\n", 13);
        return 84;
    } else
        convert_map(buffer, size);
    free(buffer);
    return a;
}

int fs_open_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);

    if (fd == -1) {
        write(2, "FAILURE\n", 9);
        return 84;
    }
    return fd;
}

int main_bsq(int nb, char **str)
{
    int fd = fs_open_file(str[1]);
    int a = 0;
    int error = error_bsq(nb);
    struct stat fileStat;

    if (stat(str[1], &fileStat) < 0)
        return 84;
    if (fd == 84 || error == 84)
        return 84;
    if (fileStat.st_size == 0)
        return 84;
    if (fd != 0)
        a = fs_understand_return_of_read(fd, fileStat.st_size);
    if (a == 84)
        return 84;
    return 0;
}