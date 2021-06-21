/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include <tetris.h>

int fs_understand_return_of_read(int fd, int size, tetris_t *tetris, bin_t *play)
{
    char *buffer = malloc(sizeof(char) * (size));
    int a = read(fd, buffer, size);

    buffer[size - 1] = '\0';
    if (a == -1) {
        write(2, "read failed\n", 13);
        return (84);
    } else
        print_stats(buffer, tetris, play);
    return (a);
}

int fs_open_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);

    if (fd == -1) {
        write(2, "FAILURE\n", 9);
        return (84);
    }
    return (fd);
}

int get_map(char *str, char *name, tetris_t *tetris, bin_t *play)
{
    struct stat fileStat;
    int fd = fs_open_file(str);

    if (tetris->keys[10].name) {
        write(1, "Tetriminos : Name ", 18);
        for (int i = 0; i < my_strlength(name) - 10; i += 1)
            write(1, &name[i], 1);
    }
    if (fd == 84)
        return (84);
    if (stat(str, &fileStat) < 0)
        return (84);
    if (fs_understand_return_of_read(fd, fileStat.st_size, tetris, play) == 84)
        return (84);
    return (0);
}