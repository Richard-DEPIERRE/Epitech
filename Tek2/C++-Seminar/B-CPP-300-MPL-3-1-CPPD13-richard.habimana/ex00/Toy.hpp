/*
** EPITECH PROJECT, 2021
** Piscine_Cpp
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
#include "Picture.hpp"

class Toy {
    public:
        enum ToyType{
            BASIC_TOY,
            ALIEN
        };
        Toy(Toy::ToyType = BASIC_TOY, const std::string &name = "toy", const std::string &filename = "");
        Toy(Toy const &toy);
        ~Toy();
        std::string const&getName() const{return _name;};
        void setName(const std::string &name) {_name = name;};
        Toy::ToyType getType() const{return _type;};
        bool setAscii(const std::string &filename){return _pic.getPictureFromFile(filename);};
        std::string const&getAscii() const{return _pic.data;};

    protected:
        Toy::ToyType _type;
        std::string _name;
        Picture _pic;

    private:
};

#endif /* !TOY_HPP_ */
