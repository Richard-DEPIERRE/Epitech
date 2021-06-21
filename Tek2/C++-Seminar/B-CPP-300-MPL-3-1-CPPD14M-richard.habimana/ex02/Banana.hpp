/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD14M-richard.habimana
** File description:
** Banana
*/

#ifndef BANANA_HPP_
#define BANANA_HPP_

#include "Fruit.hpp"

class Banana: public Fruit {
    public:
        Banana(int const &vitamin = 5, std::string const &name = "banana");
        ~Banana();

    protected:
    private:
};

#endif /* !BANANA_HPP_ */
