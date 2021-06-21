/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD14M-richard.habimana
** File description:
** FruitBox
*/

#ifndef FRUITBOX_HPP_
#define FRUITBOX_HPP_

#include "FruitNode.hpp"

class FruitBox {
    public:
        FruitBox(int size);
        ~FruitBox();
        int nbFruits() const;
        bool putFruit(Fruit *f);
        Fruit *pickFruit();
        FruitNode *head() const {
            if (_max_size == 0)
                return nullptr;
            return _fruit;
        };

    protected:
        int _max_size;
        FruitNode *_fruit;
    private:
};

#endif /* !FRUITBOX_HPP_ */
