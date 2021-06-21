/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include <tetris.h>

int get_height(char *string)
{
    int height = 0;
    char *str = NULL;

    str = my_strcpy(string, str);
    for (int j = 0; str[j]; j += 1)
        if (str[j] == '\n')
            height += 1;
    return (height + 1);
}

int get_length(char *string)
{
    int total_length = 0;
    int tmp = 0;
    int length = 0;
    char *str = NULL;

    str = my_strcpy(string, str);
    for (int i = 0; str[i]; i += 1) {
        for (; str[i] == ' ' && str[i]; i += 1);
        for (; str[i] != '\n' && str[i]; i += 1) {
            tmp = temporary_two(tmp, str[i]);
            length += 1;
        }
        for (i -= 1; str[i] == ' ' && str[i]; i -= 1)
            length -= 1;
        if (length > total_length)
            total_length = length;
        for (; str[i] != '\n' && str[i]; i += 1);
        length = 0;
        tmp = 0;
    }
    return (total_length);
}

void print_piece(char *str, int *i, pieces_t *piece, tetris_t *tetris, bin_t *play)
{
    static int pos = -1;
    int height = get_height(str + *i + 1);
    int length = get_length(str + *i + 1);

    pos += 1;
    if (height != piece->height || length != piece->length) {
        write(1, "Error\n", 6);
        return;
    }
    tetris->tetriminos[pos].x = piece->length;
    tetris->tetriminos[pos].y = piece->height;
    if (tetris->keys[10].name) {
        write(1, "Size ", 5);
        write(1, piece->length_str, my_strlength(piece->length_str));
        write(1, "*", 1);
        write(1, piece->height_str, my_strlength(piece->height_str));
        write(1, " : Color ", 9);
        write(1, piece->color_str, my_strlength(piece->color_str));
        write(1, " :\n", 3);
    }
    print_line(str, piece, tetris, play);
}

int print_numbers(char *str, int *i, char **end, tetris_t *tetris)
{
    int pos = 0;
    int j = *i + 1;

    for (; str[j] != ' ' && str[j]; j += 1);
    *end = malloc(sizeof(char) * (j + 1));
    for (*i += 1; str[*i] != ' ' && str[*i] != '\n'; *i += 1) {
        if (str[*i] < '0' || str[*i] > '9') {
            (tetris->keys[10].name) ? write(1, "Error\n", 6): (*i = *i);
            return (84);
        }
        (*end)[pos++] = str[*i];
    }
    (*end)[pos] = '\0';
    return (my_getnbr(*end));
}

void print_stats(char *str, tetris_t *tetris, bin_t *play)
{
    int i = -1;

    pieces_t *piece = malloc(sizeof(pieces_t));
    piece->height = 0;
    piece->length = 0;
    piece->color = 0;
    piece->height_str = NULL;
    piece->length_str = NULL;
    piece->color_str = NULL;
    if (tetris->keys[10].name)
        write(1, " : ", 3);
    piece->length = print_numbers(str, &i, &piece->length_str, tetris);
    if (piece->length == 84)
        return;
    piece->height = print_numbers(str, &i, &piece->height_str, tetris);
    if (piece->height == 84)
        return;
    piece->color = print_numbers(str, &i, &piece->color_str, tetris);
    if (piece->color == 84)
        return;
    print_piece(str, &i, piece, tetris, play);
}