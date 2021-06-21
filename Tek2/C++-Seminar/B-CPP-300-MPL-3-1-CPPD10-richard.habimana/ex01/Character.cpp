/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD10-richard.habimana
** File description:
** Character
*/

#include "Character.hpp"

Character::Character(const std::string &name): _name(name), _ap(40), _weapon(nullptr)
{
}

Character::~Character()
{
}

AWeapon *Character::getWeapon() const
{
    if (_weapon)
        return (_weapon);
    return (nullptr);
}

void Character::recoverAP()
{
    if (_ap < 40)
        _ap += 10;
}

void Character::equip(AWeapon *weapon)
{
    _weapon = weapon;
}

void Character::attack(AEnemy *enemy)
{
    if (!_weapon || !enemy) 
        return;
    std::cout << getName() << " attacks " << enemy->getType() << " with a " << _weapon->getName() << std::endl;
    _weapon->attack();
    enemy->takeDamage(_weapon->getDamage());
    int remove = (_ap > _weapon->getAPCost()) ? _weapon->getAPCost() : _ap;
    _ap -= remove;
    if (enemy->getHP() <= 0)
        delete enemy;
}

std::ostream &operator<<(std::ostream &os, const Character &character)
{
    if (character.getWeapon())
        return (os << character.getName() << " has " << character.getAP() << " AP and wields a " << character.getWeapon()->getName() << std::endl);
    return (os << character.getName() << " has " << character.getAP() << " AP and is unarmed" << std::endl);
}