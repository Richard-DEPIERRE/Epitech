/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush2-richard.habimana
** File description:
** LittlePony
*/

#ifndef LITTLEPONY_HPP_
#define LITTLEPONY_HPP_

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

class LittlePony: public Toy {
    public:
        LittlePony(std::string const &name);
        ~LittlePony();
        void isTaken();
    protected:
    private:
};

#endif /* !LITTLEPONY_HPP_ */
