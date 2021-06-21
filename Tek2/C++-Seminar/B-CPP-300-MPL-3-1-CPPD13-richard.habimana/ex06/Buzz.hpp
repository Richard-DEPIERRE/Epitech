/*
** EPITECH PROJECT, 2021
** Piscine_Cpp
** File description:
** Buzz
*/

#ifndef BUZZ_HPP_
#define BUZZ_HPP_

#include "Toy.hpp"

class Buzz: public Toy {
    public:
        Buzz(const std::string &name, const std::string &ascii = "buzz.txt");
        ~Buzz();
        bool speak(const std::string &statement) const override;
        bool speak_es(const std::string &statement) override;

    protected:
    private:
};

#endif /* !BUZZ_HPP_ */
