/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD14M-richard.habimana
** File description:
** Fruit
*/

#ifndef FRUIT_HPP_
#define FRUIT_HPP_

#include <fstream>
#include <string>
#include <iostream>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <list>

class Fruit {
    public:
        Fruit(int const &vitamins, std::string const &name);
        ~Fruit();
        int const &getVitamins() const{return _vitamins;};
        std::string const &getName() const{return _name;};
        void setVitamins(int const &vitamins) {_vitamins = vitamins;};

    protected:
        int _vitamins;
        std::string _name;
    private:
};

#endif /* !FRUIT_HPP_ */
