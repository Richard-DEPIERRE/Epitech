/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD01-richard.habimana
** File description:
** z
*/

#include <criterion/criterion.h>
#include "../Warrior.hpp"


Test(test_warrior , one)
{
    Warrior c("poney", 42, "hammer");
    cr_assert_eq(c.CloseAttack(), 32);
    cr_assert_eq(c.RangeAttack(), 0);
    c.CloseAttack();
    c.CloseAttack();
    c.CloseAttack();
    c.CloseAttack();
    c.CloseAttack();
    c.CloseAttack();
    c.CloseAttack();
    c.CloseAttack();
    c.CloseAttack();
    c.CloseAttack();
    c.CloseAttack();
    c.CloseAttack();
    cr_assert_eq(c.CloseAttack(), 0);
    c.Range = (Character::AttackRange)1;
    c.RangeAttack();
    c.Range = (Character::AttackRange)1;
    c.RangeAttack();
}

Test(test_warrior , errors)
{
    Warrior c("poney", 209, "hammer", "Character", "Human", 12, 5, 5, 5, 5, 1);
    c.CloseAttack();
    c.CloseAttack();
    c.CloseAttack();
    c.CloseAttack();
    cr_assert_eq(c.CloseAttack(), 0);
    c.RangeAttack();
}