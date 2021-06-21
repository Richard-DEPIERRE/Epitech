/*
** EPITECH PROJECT, 2021
** main.cpp
** File description:
** main
*/

#include "Borg.hpp"

Borg::Ship::Ship(int weaponFrequency, short repair) : _side(300), _maxWarp(9), _shield(100), _weaponFrequency(weaponFrequency), _repair(repair)
{
    _side = 300;
    _home = UNICOMPLEX;
    _location = _home;
    std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally.\nYour biological characteristics and technologies will be assimilated.\nResistance is futile." << std::endl;
}

Borg::Ship::~Ship()
{
}

void Borg::Ship::setupCore(WarpSystem::Core *core)
{
    _core = core;
}

void Borg::Ship::checkCore()
{
    if (_core->checkReactor()->isStable())
        std::cout << "Everything is in order." << std::endl;
    else
        std::cout << "Critical failure imminent." << std::endl;
}

bool Borg::Ship::move(int warp, Destination d)
{
    if (warp <= _maxWarp && d != _location && _core->checkReactor()->isStable() == true) {
        _location = d;
        return (true);
    }
    return (false);
}

bool Borg::Ship::move(int warp)
{
    if (warp <= _maxWarp && _home != _location && _core->checkReactor()->isStable() == true) {
        _location = _home;
        return (true);
    }
    return (false);
}

bool Borg::Ship::move(Destination d)
{
    if (d != _location && _core->checkReactor()->isStable() == true) {
        _location = d;
        return (true);
    }
    return (false);
}

bool Borg::Ship::move()
{

    if (_home != _location && _core->checkReactor()->isStable() == true) {
        _location = _home;
        return (true);
    }
    return (false);
}

int Borg::Ship::getShield()
{
    return (_shield);
}

void Borg::Ship::setShield(int shield)
{
    _shield = shield;
}

int Borg::Ship::getWeaponFrequency()
{
    return (_weaponFrequency);
}

void Borg::Ship::setWeaponFrequency(int frequency)
{
    _weaponFrequency = frequency;
}

short Borg::Ship::getRepair()
{
    return (_repair);
}

void Borg::Ship::setRepair(short repair)
{
    _repair = repair;
}

void Borg::Ship::fire(Federation::Starfleet::Ship *target)
{
    std::cout << "Firing on target with " << _weaponFrequency << "GW frequency." << std::endl;
    target->setShield(target->getShield() - _weaponFrequency);
}

void Borg::Ship::fire(Federation::Ship *target)
{
    std::cout << "Firing on target with " << _weaponFrequency << "GW frequency." << std::endl;
    target->getCore()->checkReactor()->setStability(false);
}

void Borg::Ship::repair()
{
    if (_repair <= 0) {
        std::cout << "Energy cells depleted , shield weakening." << std::endl;
        return;
    }
     _repair--;
    _shield = 100;
    std::cout << "Begin shield re-initialisation... Done. Awaiting further instructions." << std::endl;
}