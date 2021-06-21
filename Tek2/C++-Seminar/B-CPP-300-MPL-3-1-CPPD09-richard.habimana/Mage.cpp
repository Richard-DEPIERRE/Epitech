/*
** EPITECH PROJECT, 2021
** Mage
** File description:
** Mage
*/

#include "Mage.hpp"

Mage::Mage(const std::string &name, int level, const std::string &character, const std::string &race, int strength, int stamina, int intelligence, int spirit, int agility, int range): Character(name, level, character, race, strength, stamina, intelligence, spirit, agility, range)
{
    std::cout << getName() << " teleported" << std::endl;
}

Mage::Mage()
{
}

Mage::~Mage()
{
}

int Mage::CloseAttack()
{
    if (Range == RANGE)
        return (0);
    if (getEnergy() < 10) {
        std::cout << getName() << " out of power" << std::endl;
        return (0);
    }
    Range = RANGE;
    setEnergy(getEnergy() - 10);
    std::cout << getName() << " blinks" << std::endl;
    return (0);
}

int Mage::RangeAttack()
{
    if (getEnergy() < 25) {
        std::cout << getName() << " out of power" << std::endl;
        return (0);
    }
    setEnergy(getEnergy() - 25);
    std::cout << getName() << " launches a fire ball" << std::endl;
    return (20 + getSpirit());
}

void Mage::RestorePower()
{
    std::cout << getName() << " takes a mana potion" << std::endl;
    int energy = 50 + getIntelligence();
    int given = (100 - getEnergy() >= energy) ? energy : (100 - getEnergy());
    setEnergy(getEnergy() + given);
}