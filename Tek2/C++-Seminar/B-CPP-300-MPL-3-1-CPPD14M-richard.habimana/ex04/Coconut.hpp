/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD14M-richard.habimana
** File description:
** Coconut
*/

#ifndef COCONUT_HPP_
#define COCONUT_HPP_

#include "Fruit.hpp"

class Coconut: public Fruit {
    public:
        Coconut(int const &vitamin = 15, std::string const &name = "coconut");
        ~Coconut();

    protected:
    private:
};

#endif /* !COCONUT_HPP_ */
