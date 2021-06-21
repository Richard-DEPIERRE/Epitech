/*
** EPITECH PROJECT, 2021
** main.cpp
** File description:
** main
*/

#include "Droid.hpp"

Droid::Droid(std::string serial): _serial(serial), _energy(50), _attack(25),_toughness(15), _status(new std::string("Standing by")), BattleData(new DroidMemory())
{
    std::cout << "Droid '" << serial << "' activated" << std::endl;
}

Droid::Droid(const Droid &new_droid): _serial(new_droid.getId()), _energy(new_droid.getEnergy()), _attack(new_droid.getAttack()),_toughness(new_droid.getToughness()), _status(new std::string(*(new_droid.getStatus()))), BattleData(new DroidMemory(*(new_droid.BattleData)))
{
    std::cout << "Droid '" << new_droid.getId() << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid()
{
    if (_status)
        delete _status;
    std::cout << "Droid '" << _serial << "' destroyed" << std::endl;
}

// GET

std::string Droid::getId() const
{
    return (_serial);
}

size_t Droid::getEnergy() const
{
    return (_energy);
}

size_t Droid::getAttack() const
{
    return (_attack);
}

size_t Droid::getToughness() const
{
    return (_toughness);
}

std::string *Droid::getStatus() const
{
    return (_status);
}

// SET

void Droid::setId(std::string string)
{
    _serial = string;
}

void Droid::setEnergy(size_t energy)
{
    size_t hundred = (size_t)(100);
    size_t zero = (size_t)(0);
    _energy = energy > hundred ? hundred : energy < zero ? zero : energy;
}

void Droid::setStatus(std::string *string)
{
    delete(_status);
    _status = string;
}

Droid &Droid::operator<<(size_t &new_energy)
{
    size_t hundred = (size_t)(100);
    size_t given = ((hundred - _energy) > new_energy) ? new_energy : (hundred - _energy);

    if (_energy == hundred)
        return(*this);
    _energy += given;
    new_energy -= given;
    return(*this);
}


bool Droid::operator==(const Droid &new_droid) const
{
    return (new_droid.getStatus() == _status);
}

bool Droid::operator!=(const Droid &new_droid) const
{
    return (new_droid.getStatus() != _status);
}

std::ostream &operator<<(std::ostream &os, const Droid &new_droid)
{
    return(os << "Droid '" << new_droid.getId() << "', " << *(new_droid.getStatus()) << ", " << new_droid.getEnergy());
}

Droid &Droid::operator=(Droid const & new_droid)
{
    _serial = new_droid._serial;
    _energy = new_droid._energy;
    setStatus(new std::string(*(new_droid.getStatus())));
    return(*this);
}

DroidMemory *Droid::getBattleData() const
{
    return (BattleData);
}
void Droid::setBattleData(const DroidMemory *droid)
{
    BattleData = new DroidMemory(*droid);
}