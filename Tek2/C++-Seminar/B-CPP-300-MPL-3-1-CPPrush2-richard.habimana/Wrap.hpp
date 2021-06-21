/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush2-richard.habimana
** File description:
** Wrap
*/

#ifndef WRAP_HPP_
#define WRAP_HPP_

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
#include "Toy.hpp"

class Wrap: public Object {
    public:
        Wrap();
        ~Wrap();
        virtual bool wrapMeThat(Object *obj) = 0;
        virtual Object *openMe() = 0;
        virtual void closeMe() = 0;
    protected:
        bool _isOpen;
    private:
};

#endif /* !WRAP_HPP_ */
