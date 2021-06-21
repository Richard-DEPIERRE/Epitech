/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD14M-richard.habimana
** File description:
** FruitNode
*/

#ifndef FRUITNODE_HPP_
#define FRUITNODE_HPP_

#include "Fruit.hpp"

class FruitNode {
    public:
        Fruit *fruit;
        FruitNode *next;
};

#endif /* !FRUITNODE_HPP_ */
