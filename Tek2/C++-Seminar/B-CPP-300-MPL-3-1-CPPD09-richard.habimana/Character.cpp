/*
** EPITECH PROJECT, 2021
** character
** File description:
** character
*/

#include "Character.hpp"

Character::Character(const std::string &name, int level, const std::string &character, const std::string &race, int strength, int stamina, int intelligence, int spirit, int agility, int range): _name(name), _level(level), _character(character), _race(race), _health(100), _energy(100), _strength(strength), _stamina(stamina), _intelligence(intelligence), _spirit(spirit), _agility(agility), Range((Character::AttackRange)range)
{
    std::cout << getName() << " Created" << std::endl;
}

Character::Character()
{
}

Character::~Character()
{
}

int Character::CloseAttack()
{
    if (Range == RANGE)
        return (0);
    if (_energy < 10) {
        std::cout << getName() << " out of power" << std::endl;
        return (0);
    }
    setEnergy(getEnergy() - 10);
    std::cout << getName() << " strikes with a wooden stick" << std::endl;
    return (getStrength() + 10);
}

void Character::Heal()
{
    std::cout << getName() << " takes a potion" << std::endl;
    int given = (100 - getHealth() >= 50) ? 50 : (100 - getHealth());
    setHealth(getHealth() + given);
}

int Character::RangeAttack()
{
    if (_energy < 10) {
        std::cout << getName() << " out of power" << std::endl;
        return (0);
    }
    setEnergy(getEnergy() - 10);
    std::cout << getName() << " tosses a stone" << std::endl;
    return (getStrength() + 5);
}

void Character::RestorePower()
{
    std::cout << getName() << " eats" << std::endl;
    int given = (100 - getEnergy() >= 50) ? 50 : (100 - getEnergy());
    setEnergy(getEnergy() + given);
}

void Character::TakeDamage(const int damage)
{
    if (getHealth() - damage <= 0) {
        setHealth(0);
        std::cout << getName() << " out of combat" << std::endl;
        return;
    }
    setHealth(getHealth() - damage);
    std::cout << getName() << " takes " << damage << " damage" << std::endl;
}