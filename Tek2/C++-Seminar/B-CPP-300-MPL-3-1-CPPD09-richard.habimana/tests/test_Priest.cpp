/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD01-richard.habimana
** File description:
** z
*/

#include <criterion/criterion.h>
#include "../Priest.hpp"


Test(test_priest , one)
{
    Priest c("poney", 42, "hammer");
    cr_assert_eq(c.CloseAttack(), 0);
    cr_assert_eq(c.RangeAttack(), 41);
    c.RangeAttack();
    c.RangeAttack();
    c.RangeAttack();
    c.RangeAttack();
    c.RangeAttack();
    c.RangeAttack();
    c.RangeAttack();
    c.RangeAttack();
    c.RangeAttack();
    c.RangeAttack();
    c.RangeAttack();
    cr_assert_eq(c.RangeAttack(), 0);
    c.RangeAttack();
    c.Range = (Character::AttackRange)0;
    cr_assert_eq(c.Range, 0);
    c.CloseAttack();
    c.Heal();
    c.RestorePower();
    c.Heal();
}

Test(test_priest , errors)
{
    Priest c("poney", 209, "Character", "Human", 12, 5, 5, 5, 5, 0);
    c.CloseAttack();
    c.RangeAttack();
    c.RangeAttack();
    c.RangeAttack();
    c.RangeAttack();
    c.RangeAttack();
    cr_assert_eq(c.CloseAttack(), 0);
    c.RangeAttack();
}