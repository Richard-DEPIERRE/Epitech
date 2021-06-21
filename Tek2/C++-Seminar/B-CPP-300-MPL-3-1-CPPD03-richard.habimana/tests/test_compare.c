/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD01-richard.habimana
** File description:
** z
*/

#include "../string.h"
#include <criterion/criterion.h>

Test(test_compare , hello_world)
{
    string_t s;
    string_t t;
    string_init(&t, "Balek");
    string_init (&s, "Hello World");
    cr_assert_eq(6, s.compare_s(&s, &t));
    cr_assert_eq(-7, s.compare_c(&s, "Ok forever\0"));
    string_destroy(&s);
    string_destroy(&t);
}