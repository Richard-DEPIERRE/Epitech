/*
** EPITECH PROJECT, 2021
** main.cpp
** File description:
** main
*/

#include "Federation.hpp"

// SHIP

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp, int torpedo): _shield(100)
{
    _length = length;
    _width = width;
    _name = name;
    _maxWarp = maxWarp;
    _core = nullptr;
    _captain = nullptr;
    _home = EARTH;
    _location = _home;
    _photonTorpedo = torpedo;
    std::cout << "The ship USS " << name << " has been finished." << std::endl;
    std::cout << "It is " << length << " m in length and " << width << " m in width." << std::endl;
    std::cout << "It can go to Warp " << maxWarp << "!" << std::endl;
    if (torpedo)
        std::cout << "Weapons are set: " << _photonTorpedo << " torpedoes ready." << std::endl;
}

Federation::Starfleet::Ship::~Ship()
{
}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core)
{
    _core = core;
    std::cout << "USS " << _name << ": The core is set." << std::endl;
}

void Federation::Starfleet::Ship::checkCore()
{
    std::cout << "USS " << _name << ": The core is ";
    if (_core->checkReactor()->isStable())
        std::cout << "stable at the time." << std::endl;
    else
        std::cout << "unstable at the time." << std::endl;
}

void Federation::Starfleet::Ship::promote(Captain *captain)
{
    _captain = captain;
    std::cout << captain->getName() << ": I'm glad to be the captain of the USS " << _name << "." << std::endl;
}

bool Federation::Starfleet::Ship::move(int warp, Destination d)
{
    if (warp <= _maxWarp && d != _location && _core->checkReactor()->isStable() == true) {
        _location = d;
        return (true);
    }
    return (false);
}

bool Federation::Starfleet::Ship::move(int warp)
{
    if (warp <= _maxWarp && _home != _location && _core->checkReactor()->isStable() == true) {
        _location = _home;
        return (true);
    }
    return (false);
}

bool Federation::Starfleet::Ship::move(Destination d)
{
    if (d != _location && _core->checkReactor()->isStable() == true) {
        _location = d;
        return (true);
    }
    return (false);
}

bool Federation::Starfleet::Ship::move()
{

    if (_home != _location && _core->checkReactor()->isStable() == true) {
        _location = _home;
        return (true);
    }
    return (false);
}

int Federation::Starfleet::Ship::getShield()
{
    return (_shield);
}

void Federation::Starfleet::Ship::setShield(int shield)
{
    _shield = shield;
}

int Federation::Starfleet::Ship::getTorpedo()
{
    return (_photonTorpedo);
}

void Federation::Starfleet::Ship::setTorpedo(int torpedo)
{
    _photonTorpedo = torpedo;
}

void Federation::Starfleet::Ship::fire(Borg::Ship *target)
{
    if (!_photonTorpedo) {
        std::cout << _name << ": No enough torpedoes to fire, " << _captain->getName() << "!" << std::endl;
        return;
    }
    _photonTorpedo--;
    std::cout << _name << ": Firing on target. " << _photonTorpedo << " torpedoes remaining." << std::endl;
    target->setShield(target->getShield() - 50);
    if (!_photonTorpedo)
        std::cout << _name << ": No more torpedo to fire, " << _captain->getName() << "!" << std::endl;
}

void Federation::Starfleet::Ship::fire(int torpedoes , Borg::Ship *target)
{
    if (_photonTorpedo - torpedoes < 0) {
        std::cout << _name << ": No enough torpedoes to fire, " << _captain->getName() << "!" << std::endl;
        return;
    }
    _photonTorpedo -= torpedoes;
    std::cout << _name << ": Firing on target. " << _photonTorpedo << " torpedoes remaining." << std::endl;
    target->setShield(target->getShield() - (50 * torpedoes));
    if (!_photonTorpedo)
        std::cout << _name << ": No more torpedo to fire, " << _captain->getName() << "!" << std::endl;
}

// INDEPENDANT RUSH

Federation::Ship::Ship(int length, int width, std::string name, short maxWarp)
{
    _length = length;
    _width = width;
    _name = name;
    _core = nullptr;
    _home = VULCAN;
    _location = _home;
    _maxWarp = maxWarp;
    std::cout << "The independent ship " << _name << " just finished its construction.\nIt is " << length << " m in length and " << width << " m in width." << std::endl;
}

Federation::Ship::~Ship()
{
}

void Federation::Ship::setupCore(WarpSystem::Core *core)
{
    _core = core;
    std::cout << _name << ": The core is set." << std::endl;
}

void Federation::Ship::checkCore()
{
    std::cout << _name << ": The core is ";
    if (_core->checkReactor()->isStable())
        std::cout << "stable at the time." << std::endl;
    else
        std::cout << "unstable at the time." << std::endl;
}

bool Federation::Ship::move(int warp, Destination d)
{
    if (warp <= _maxWarp && d != _location && _core->checkReactor()->isStable() == true) {
        _location = d;
        return (true);
    }
    return (false);
}

bool Federation::Ship::move(int warp)
{
    if (warp <= _maxWarp && _home != _location && _core->checkReactor()->isStable() == true) {
        _location = _home;
        return (true);
    }
    return (false);
}

bool Federation::Ship::move(Destination d)
{
    if (d != _location && _core->checkReactor()->isStable() == true) {
        _location = d;
        return (true);
    }
    return (false);
}

bool Federation::Ship::move()
{

    if (_home != _location && _core->checkReactor()->isStable() == true) {
        _location = _home;
        return (true);
    }
    return (false);
}

WarpSystem::Core *Federation::Ship::getCore()
{
    return (_core);
}

// CAPTAIN

Federation::Starfleet::Captain::Captain(std::string name, int age)
{
    _name = name;
    _age = age;
}

Federation::Starfleet::Captain::~Captain()
{
}

std::string Federation::Starfleet::Captain::getName()
{
    return (_name);
}

int Federation::Starfleet::Captain::getAge()
{
    return (_age);
}

void Federation::Starfleet::Captain::setAge(int age)
{
    _age = age;
}

// ENSIGN

Federation::Starfleet::Ensign::Ensign(std::string name)
{
    _name = name;
    std::cout << "Ensign " << _name << ", awaiting orders." << std::endl;
}

Federation::Starfleet::Ensign::~Ensign()
{
}