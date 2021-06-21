/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD14M-richard.habimana
** File description:
** LittleHand
*/

#ifndef LITTLEHAND_HPP_
#define LITTLEHAND_HPP_

#include "FruitBox.hpp"
#include "Lemon.hpp"
#include "Lime.hpp"
#include "Banana.hpp"
#include "Coconut.hpp"
#include "Mixer.hpp"

class LittleHand {
    public:
        LittleHand();
        ~LittleHand();
        static void sortFruitBox(FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox & limes);
        static FruitBox * const *organizeCoconut(Coconut const * const *coconuts);
        static void injectVitamin(Fruit &f, int quantity);
        void plugMixer(MixerBase &mixer);

    protected:
    private:
};

#endif /* !LITTLEHAND_HPP_ */
