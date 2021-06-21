/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD01-richard.habimana
** File description:
** z
*/

#include "../string.h"
#include <criterion/criterion.h>

Test(test_copy , hello_world)
{
    string_t s;
    string_init (&s, "Hello World");
    char *test = calloc(6, sizeof(char));
    cr_assert_eq(5, s.copy(&s, test, 5, 6));
    cr_assert_str_eq("World", test);
    free(test);
    string_destroy(&s);
}

Test(test_copy , null)
{
    string_t s;
    string_init (&s, "Hello World");
    char *test = calloc(6, sizeof(char));
    cr_assert_eq(12, s.copy(&s, test, -1, 6));
    cr_assert_str_eq("World", test);
    free(test);
    string_destroy(&s);
}