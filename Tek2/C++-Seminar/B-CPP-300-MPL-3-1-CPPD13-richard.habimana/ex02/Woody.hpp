/*
** EPITECH PROJECT, 2021
** Piscine_Cpp
** File description:
** Woody
*/

#ifndef WOODY_HPP_
#define WOODY_HPP_

#include "Toy.hpp"

class Woody: public Toy {
    public:
        Woody(const std::string &name, const std::string &ascii = "woody.txt");
        ~Woody();

    protected:
    private:
};

#endif /* !WOODY_HPP_ */
