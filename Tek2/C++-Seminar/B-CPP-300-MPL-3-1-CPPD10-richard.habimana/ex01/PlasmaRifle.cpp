/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD10-richard.habimana
** File description:
** PlasmaRifle
*/

#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle(): AWeapon("Plasma Rifle", 5, 21)
{
}

PlasmaRifle::~PlasmaRifle()
{
}

void PlasmaRifle::attack() const
{
    std::cout << "* piouuu piouuu piouuu *" << std::endl;
}