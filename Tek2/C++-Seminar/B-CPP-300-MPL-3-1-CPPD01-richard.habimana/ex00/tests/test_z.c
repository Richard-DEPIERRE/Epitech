/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD01-richard.habimana
** File description:
** z
*/

#include <criterion/criterion.h>

int print_z(void);

Test(my_strlen , positive_return_value)
{
    cr_assert_eq(print_z(), 0);
}