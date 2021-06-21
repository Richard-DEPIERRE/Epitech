/*
** EPITECH PROJECT, 2021
** Piscine_Cpp
** File description:
** ToyStory
*/

#ifndef TOYSTORY_HPP_
#define TOYSTORY_HPP_

#include <string>
#include "Toy.hpp"
#include "Buzz.hpp"
#include "Woody.hpp"

class ToyStory {
    public:
        ToyStory();
        ~ToyStory();
        static bool tellMeAStory(std::string const &filename, Toy &toy1, bool (Toy::*funct1)(std::string const &message) const, Toy &toy2, bool (Toy::*funct2)(std::string const &message) const);
    protected:
    private:
};

#endif /* !TOYSTORY_HPP_ */
