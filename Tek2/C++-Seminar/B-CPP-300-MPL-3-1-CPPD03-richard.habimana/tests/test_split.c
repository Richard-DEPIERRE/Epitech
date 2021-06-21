/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD01-richard.habimana
** File description:
** z
*/

#include "../string.h"
#include <criterion/criterion.h>

Test(test_split , hello_world)
{
    string_t s;
    string_t **ret_two;

    string_init(&s, "Bonjour,Comment,,Tu,Vas");
    char **ret = s.split_c(&s, ',');
    ret_two = s.split_s(&s, ',');
    cr_assert_eq(5, 5);
    for (int i = 0; ret[i]; i += 1)
        free(ret[i]);
    free(ret);
    for (int i = 0; ret_two[i]; i ++) {
        free(ret_two[i]->str);
        free(ret_two[i]);
    }
    free(ret_two);
    string_destroy(&s);
}