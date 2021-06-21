/*
** EPITECH PROJECT, 2019
** test_bsq_2
** File description:
** test 2 in bsq
*/

#include <stdio.h>
#include <criterion/criterion.h>

int main_bsq(int nb, char **str);

Test(bsq_o, no_files_found6)
{
    char **str = malloc(sizeof(str) * 3);

    str[0] = malloc(sizeof(str[0]) * 6);
    str[0] = "./bsq\0";
    str[1] = malloc(sizeof(str[1]) * 47);
    str[1] = "../mouli_maps/intermediate_map_one_empty_line\0";
    cr_assert_eq(main_bsq(2, str), 0);
    free(str);
}

Test(bsq_o, no_files_found7)
{
    char **str = malloc(sizeof(str) * 3);

    str[0] = malloc(sizeof(str[0]) * 6);
    str[0] = "./bsq\0";
    str[1] = malloc(sizeof(str[1]) * 65);
    str[1] = "../mouli_maps/intermediate_map_187_187_with_obstacles_50pc\0";
    cr_assert_eq(main_bsq(2, str), 0);
    free(str);
}
