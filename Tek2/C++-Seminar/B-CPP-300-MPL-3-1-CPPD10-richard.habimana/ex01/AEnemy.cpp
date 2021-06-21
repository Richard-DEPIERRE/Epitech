/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD10-richard.habimana
** File description:
** AEnemy
*/

#include "AEnemy.hpp"

AEnemy::AEnemy(int hp, const std::string &type): _hp(hp), _type(type)
{
}

AEnemy::~AEnemy()
{
}

void AEnemy::takeDamage(int damage)
{
    if (damage < 0)
        return;
    setHP(getHP() - damage);
}