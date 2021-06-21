/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush2-richard.habimana
** File description:
** Teddy
*/

#ifndef TEDDY_HPP_
#define TEDDY_HPP_

#include <fstream>
#include <string>
#include <iostream>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <list>
#include <array>
#include "Toy.hpp"

class Teddy: virtual public Toy {
    public:
        Teddy(std::string const &name);
        ~Teddy();
        void isTaken();
    protected:
    private:
};

#endif /* !TEDDY_HPP_ */
