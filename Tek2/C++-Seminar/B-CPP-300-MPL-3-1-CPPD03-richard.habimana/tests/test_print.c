/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD01-richard.habimana
** File description:
** z
*/

#include "../string.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(test_print , hello_world)
{
    string_t s;

    string_init (&s, "Hello World");
    s.print(&s);
    cr_assert_eq(0, 0);
    string_destroy(&s);
}