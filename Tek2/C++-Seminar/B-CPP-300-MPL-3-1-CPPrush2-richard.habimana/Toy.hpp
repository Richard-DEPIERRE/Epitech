/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush2-richard.habimana
** File description:
** Toy
*/

#ifndef TOY_HPP_
#define TOY_HPP_

#include <fstream>
#include <string>
#include <iostream>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <list>
#include <array>
#include "Object.hpp"

class Toy: virtual public Object {
    public:
        Toy(const std::string &title);
        virtual ~Toy();
        virtual void isTaken() = 0;
    protected:
    private:
};

#endif /* !TOY_HPP_ */
