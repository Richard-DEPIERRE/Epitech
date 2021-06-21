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

FruitBox * const *LittleHand::organizeCoconut(Coconut const * const *coconuts)
{
    if (coconuts == nullptr)
        return (nullptr);
    int count = 0;
    for (; coconuts[count]; count++);
    count /= (count % 6) ? 7 : 6;
    FruitBox **res = new FruitBox*[count];
    count = 0;
    for (int i = 0; coconuts[i]; i++) {
        if (i % 6 == 0) {
            if (i != 0)
                count ++;
            res[count] = new FruitBox(6);
        }
        res[count]->putFruit(const_cast<Coconut *>(coconuts[i]));
    }
    return res;
}

void LittleHand::plugMixer(MixerBase &mixer)
{
    mixer = *(new Mixer());
}