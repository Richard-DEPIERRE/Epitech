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

class LittleHand {
    public:
        LittleHand();
        ~LittleHand();
        static void sortFruitBox(FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox & limes);

    protected:
    private:
};

#endif /* !LITTLEHAND_HPP_ */
