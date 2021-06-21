/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD10-richard.habimana
** File description:
** AWeapon
*/

#include "AWeapon.hpp"

AWeapon::AWeapon(const std::string &name, int apcost, int damage): _name(name), _apcost(apcost), _damage(damage)
{
}

AWeapon::~AWeapon()
{
}