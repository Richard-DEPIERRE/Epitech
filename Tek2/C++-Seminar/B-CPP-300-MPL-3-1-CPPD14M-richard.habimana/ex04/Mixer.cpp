/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD14M-richard.habimana
** File description:
** Mixer
*/

#include "Mixer.hpp"

int Mix(FruitBox& fruits)
{
    Fruit *fruit = fruits.pickFruit();
    int vitamins = 0;
    for (;fruit; fruit = fruits.pickFruit())
        vitamins += fruit->getVitamins();
    return vitamins;
}

Mixer::Mixer()
{
    _plugged = true;
    _mixfunc = &Mix;
}

Mixer::~Mixer()
{
}
