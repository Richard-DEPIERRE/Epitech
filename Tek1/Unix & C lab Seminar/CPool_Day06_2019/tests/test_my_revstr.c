/*
** EPITECH PROJECT, 2019
** test_my_revstr
** File description:
** test my revstr
*/

#include <criterion/criterion.h>

char *my_revstr(char *str);

Test(my_revstr, copy_string_in_empty_array)
{
    char my_dest[] = "hello";
    char dest[] = "olleh";

    my_revstr(my_dest);
    cr_assert_str_eq(my_dest, dest);
}
