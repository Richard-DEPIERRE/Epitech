/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD01-richard.habimana
** File description:
** z
*/

#include "../string.h"
#include <criterion/criterion.h>

Test(test_clear , hello_world)
{
    string_t t;
    char *str = NULL;

    str = (char *)calloc(1, sizeof(char));
    str[0] = '\0';
    string_init(&t, "Balek");
    t.clear(&t);
    cr_assert_eq(sizeof(str), sizeof(t.str));
    string_destroy(&t);
}