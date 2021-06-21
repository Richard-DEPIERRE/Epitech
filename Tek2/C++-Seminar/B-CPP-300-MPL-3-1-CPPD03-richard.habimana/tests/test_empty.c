/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD01-richard.habimana
** File description:
** z
*/

#include "../string.h"
#include <criterion/criterion.h>

Test(test_empty , hello_world)
{
    string_t t;
    string_init (&t, "12");
    cr_assert_eq(0, t.empty(&t));
    string_destroy(&t);
}

Test(test_empty , null)
{
    string_t t;
    string_init (&t, NULL);
    cr_assert_eq(1, t.empty(&t));
    string_destroy(&t);
}

Test(test_empty , empty)
{
    string_t t;
    string_init (&t, "\0");
    cr_assert_eq(1, t.empty(&t));
    string_destroy(&t);
}