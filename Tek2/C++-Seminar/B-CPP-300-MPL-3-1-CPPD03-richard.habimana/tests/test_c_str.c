/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD01-richard.habimana
** File description:
** z
*/

#include "../string.h"
#include <criterion/criterion.h>

Test(test_c_str , hello_world)
{
    string_t s;
    string_init (&s, "Hello World");
    cr_assert_str_eq("Hello World", s.c_str(&s));
    string_destroy(&s);
}