/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD14M-richard.habimana
** File description:
** LittleHand
*/

#include "LittleHand.hpp"

LittleHand::LittleHand()
{
}

LittleHand::~LittleHand()
{
}

void LittleHand::sortFruitBox(FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox & limes)
{
    int size = unsorted.nbFruits();
    for (int i = 0; i < size; i++) {
        Fruit *fruit = unsorted.pickFruit();
        bool error = true;
        if (fruit->getVitamins() == 5 && fruit->getName() == "banana")
            error = bananas.putFruit(fruit);
        else if (fruit->getVitamins() == 3 && fruit->getName() == "lemon")
            error = lemons.putFruit(fruit);
        else if (fruit->getVitamins() == 2 && fruit->getName() == "lime")
            error = limes.putFruit(fruit);
        else
            error = unsorted.putFruit(fruit);
        if (error == false)
            error = unsorted.putFruit(fruit);
    }
}
