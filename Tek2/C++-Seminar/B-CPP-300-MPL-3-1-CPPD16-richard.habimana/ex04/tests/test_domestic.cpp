/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD01-richard.habimana
** File description:
** z
*/

#include <criterion/criterion.h>
#include <ostream>
#include <cstdlib>
#include <iostream>
#include "../Parser.hpp"

Test(test_Parser , one)
{
    Parser p;
    p.feed("((12*2)+14)");
    cr_assert_eq(38, p.result());
}

Test(test_Parser , two)
{
    Parser p;
    p.feed("((12*2)+14)");
    p.feed("((17 % 9) / 4)");
    cr_assert_eq(40, p.result());
}

Test(test_Parser , three)
{
    Parser p;
    p.feed("((12*2)+14)");
    p.feed("((17 % 9) / 4)");
    p.feed("(17 / 3 * 4 + 3 * (4 * 13))");
    p.reset();
    p.feed("(17 - (4 * 13))");
    cr_assert_eq(-35, p.result());
    p.feed("(((133 / 5) + 6) * ((45642 % 127) - 21))");
}

Test(test_Parser , four)
{
    Parser p;
    p.feed("((12*2)+14)");
    p.feed("((17 % 9) / 4)");
    p.reset();
    p.feed("(17 - (4 * 13))");
    p.feed("(((133 / 5) + 6) * ((45642 % 127) - 21))");
    cr_assert_eq(861, p.result());
}