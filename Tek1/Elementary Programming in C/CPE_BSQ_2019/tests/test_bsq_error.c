/*
** EPITECH PROJECT, 2019
** test_bsq_error
** File description:
** test errors in bsq
*/

#include <stdio.h>
#include <criterion/criterion.h>

int main_bsq(int nb, char **str);

Test(bsq_m, no_files_found)
{
    char **str = malloc(sizeof(*str) * 3);

    str[0] = malloc(sizeof(char) * 6);
    str[0] = "./bsq\0";
    str[1] = malloc(sizeof(char) * 3);
    str[1] = "-g\0";
    cr_assert_eq(main_bsq(2, str), 84);
    free(str);
}

Test(bsq_m, no_files_found2)
{
    char **str = malloc(sizeof(str) * 3);

    str[0] = malloc(sizeof(str[0]) * 6);
    str[0] = "./bsq\0";
    str[1] = malloc(sizeof(str[1]) * 16);
    str[1] = "tests/test.txt\0";
    cr_assert_eq(main_bsq(2, str), 0);
    free(str);
}

Test(bsq_m, no_files_found3)
{
    char **str = malloc(sizeof(str) * 4);

    str[0] = malloc(sizeof(str[0]) * 6);
    str[0] = "./bsq\0";
    str[1] = malloc(sizeof(str[1]) * 47);
    str[1] = "tests/mouli_maps/intermediate_map_34_137_empty\0";
    str[2] = malloc(sizeof(str[2]) * 3);
    str[2] = "l\0";
    cr_assert_eq(main_bsq(3, str), 84);
    free(str);
}

Test(bsq_m, no_files_found4)
{
    char **str = malloc(sizeof(str) * 3);

    str[0] = malloc(sizeof(str[0]) * 6);
    str[0] = "./bsq\0";
    str[1] = malloc(sizeof(str[1]) * 16);
    str[1] = "tests/test.txt\0";
    cr_assert_eq(main_bsq(1, str), 84);
    free(str);
}

Test(bsq_m, no_files_found5)
{
    char **str = malloc(sizeof(str) * 3);

    str[0] = malloc(sizeof(str[0]) * 6);
    str[0] = "./bsq\0";
    str[1] = malloc(sizeof(str[1]) * 17);
    str[1] = "tests/test2.txt\0";
    cr_assert_eq(main_bsq(2, str), 84);
    free(str);
}