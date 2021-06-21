/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD01-richard.habimana
** File description:
** z
*/

#include "../string.h"
#include <criterion/criterion.h>

Test(test_append , hello_world)
{
    string_t s;
    string_t t;
    string_init(&t, "Balek");
    string_init (&s, "Hello World");
    s.append_c(&s, " forever");
    cr_assert_str_eq("Hello World forever", s.str);
    s.append_s(&s, &t);
    cr_assert_str_eq("Hello World foreverBalek", s.str);
    string_destroy(&s);
    string_destroy(&t);
}

Test(test_append , null)
{
    string_t s;
    string_t t;
    string_init(&t, "Balek");
    string_init (&s, NULL);
    s.append_c(&s, " forever");
    cr_assert_str_eq(" forever", s.str);
    s.append_s(&s, &t);
    cr_assert_str_eq(" foreverBalek", s.str);
    string_destroy(&s);
    string_destroy(&t);
}