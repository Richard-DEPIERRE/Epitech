/*
** EPITECH PROJECT, 2019
** map
** File description:
** open and read map
*/

#include "my_runner.h"

void fill_map(all_struct_t *runner)
{
    int count = 0;
    int j = 0;
    int i = 0;

    for (i = 0; i < runner->map.height; i += 1) {
        for (j = 0;runner->map.str[count] != '\n'
        && runner->map.str[count] != '\0'; j += 1) {
            runner->map.map[i][j] = runner->map.str[count];
            count += 1;
        }
        runner->map.map[i][j] = '\0';
        count += 1;
    }
    runner->map.map[i] = NULL;
}

void make_arr_from_str(all_struct_t *runner)
{
    int count = 0;
    int j = 0;

    runner->map.height = 0;
    for (int i = 0; i < runner->map.size; i += 1)
        if (runner->map.str[i] == '\n') {
            runner->map.height += 1;
        }
    runner->map.height += 1;
    runner->map.map = malloc(sizeof(char *) * (runner->map.height + 1));
    for (int i = 0; i < runner->map.height; i += 1) {
        for (j = 0; runner->map.str[count] != '\n'
        && runner->map.str[count] != '\0'; j += 1) {
            count += 1;
        }
        runner->map.map[i] = malloc(sizeof(char) * (j + 1));
        count += 1;
    }
    fill_map(runner);
}

void get_pos(all_struct_t *runner)
{
    int count = 0;
    runner->prim.size = 0;

    runner->map.number_of_tnt = 0;
    for (; runner->map.map[1][runner->prim.size]; runner->prim.size += 1);
    runner->prim.size *= 120;
    for (int i = 0; runner->map.map[i]; i += 1)
        for (int j = 0; runner->map.map[i][j]; j += 1)
            if (runner->map.map[i][j] == '1')
                runner->map.number_of_tnt += 1;
    runner->map.pos = malloc(sizeof(sfVector2f) * \
    (runner->map.number_of_tnt + 1));
    for (int i = 0; runner->map.map[i]; i += 1)
        for (int j = 0; runner->map.map[i][j]; j += 1)
            if (runner->map.map[i][j] == '1') {
                runner->map.pos[count] = (sfVector2f){j * 120, (i * 120) - 80};
                count += 1;
            }
    runner->map.pos[count] = (sfVector2f){-1, -1};
    runner->map.size_map = runner->map.number_of_tnt + 9;
}

void map(all_struct_t *runner, char *str)
{
    int fd = open(str, O_RDONLY);
    int a = 0;

    runner->map.str = malloc(sizeof(char) * (10000));
    a = read(fd, runner->map.str, 10000);
    runner->map.str[a] = '\0';
    runner->map.size = a;
    make_arr_from_str(runner);
    get_pos(runner);
}