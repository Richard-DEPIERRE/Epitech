/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD14M-richard.habimana
** File description:
** Lemon
*/

#ifndef LEMON_HPP_
#define LEMON_HPP_

#include "Fruit.hpp"

class Lemon: public Fruit {
    public:
        Lemon(int const &vitamin = 3, std::string const &name = "lemon");
        ~Lemon();

    protected:
    private:
};

#endif /* !LEMON_HPP_ */
