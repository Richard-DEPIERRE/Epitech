/*
** EPITECH PROJECT, 2021
** main.cpp
** File description:
** main
*/

#include "BorgQueen.hpp"

Borg::BorgQueen::BorgQueen(): movePtr(&Borg::Ship::move), firePtr(&Borg::Ship::fire), destroyPtr(&Borg::Ship::fire)
{
}

Borg::BorgQueen::~BorgQueen()
{
}

bool Borg::BorgQueen::move(Borg::Ship* ship, Destination dest)
{
    return(ship->*movePtr)(dest);
}

void Borg::BorgQueen::fire(Borg::Ship* ship, Federation::Starfleet::Ship* enemy)
{
    (ship->*firePtr)(enemy);
}

void Borg::BorgQueen::destroy(Borg::Ship* ship, Federation::Ship* enemy)
{
    (ship->*destroyPtr)(enemy);
}