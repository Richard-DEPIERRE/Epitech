/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD01-richard.habimana
** File description:
** z
*/

#include "../string.h"
#include <criterion/criterion.h>

Test(test_to_int , hello_world)
{
    string_t t;
    string_init (&t, "12");
    cr_assert_eq(12, t.to_int(&t));
    string_destroy(&t);
}