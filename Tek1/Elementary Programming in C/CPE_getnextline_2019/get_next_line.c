/*
** EPITECH PROJECT, 2019
** getnextline
** File description:
** main file for getnextline
*/

#include "get_next_line.h"

int my_strlen4(char const *str)
{
    int count = 0;

    if (str == NULL)
        return (0);
    while (str[count] != '\0') {
        count++;
    }
    return (count);
}

char *my_strcat(char *dest, char *src)
{
    int count = 0;
    int i = 0;
    char *res = NULL;

    count = my_strlen4(dest) ;
    res = malloc(sizeof(char) * (count + my_strlen4(src) + 1));
    while (dest[i] != '\0' && dest != NULL) {
        res[i] = dest[i];
        i += 1;
    }
    for (int j = 0; src[j]; j += 1) {
        res[i] = src[j];
        i += 1;
    }
    res[i] = '\0';
    return (res);
}

void get_next_line2(get_line_t *line, int *pos, char *str2, int fd)
{
    for (int tmp = 0; tmp == 0; *pos += 1) {
        if (str2[*pos] == '\n') {
            line->res = my_strcat(line->res, line->str);
            for (int j = 0; line->str[j]; j += 1)
                line->str[j] = '\0';
            break;
        }
        if (str2[*pos] == '\0') {
            line->res = my_strcat(line->res, line->str);
            line->a = read(fd, str2, READ_SIZE);
            if (line->a <= 0)
                break;
            str2[READ_SIZE] = '\0';
            for (int j = 0; line->str[j]; j += 1)
                line->str[j] = '\0';
            *pos = -1;
            line->i = 0;
        } else
            line->str[line->i++] = str2[*pos];
    }
}

char *get_next_line(int fd)
{
    get_line_t line;
    static char *str2;
    static int pos = 0;
    static int check = 0;
    line.res = malloc(sizeof(char) * 1);
    line.str = malloc(sizeof(char) * (READ_SIZE + 1));
    line.a = 0;
    line.i = 0;

    if (!line.str)
        return NULL;
    if (fd < 0 || READ_SIZE < 1)
        return NULL;
    if (check == 0) {
        str2 = malloc(sizeof(char) * (READ_SIZE + 1));
        line.a = read(fd, str2, READ_SIZE);
        if (line.a <= 0)
            return NULL;
        str2[READ_SIZE] = '\0';
        check = 1;
    }
    for (int j = 0; j <= READ_SIZE; j += 1)
        line.str[j] = '\0';
    line.res[0] = '\0';
    if (str2[pos] == '\n')
        pos += 1;
    if (str2[pos] == '\0')
        return NULL;
    get_next_line2(&line, &pos, str2, fd);
    free(line.str);
    check = 1;
    return (line.res);
}