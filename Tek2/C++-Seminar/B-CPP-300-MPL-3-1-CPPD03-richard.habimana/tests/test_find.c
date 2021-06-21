/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD01-richard.habimana
** File description:
** z
*/

#include "../string.h"
#include <criterion/criterion.h>

Test(test_find , hello_world)
{
    string_t s;
    string_t t;
    string_init(&t, "Balek");
    string_init (&s, "Hello World");
    cr_assert_eq(-1, s.find_s(&s, &t, 2));
    cr_assert_eq(6, s.find_c(&s, "World", 3));
    string_destroy(&s);
    string_destroy(&t);
}