/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD14M-richard.habimana
** File description:
** Lime
*/

#ifndef LIME_HPP_
#define LIME_HPP_

#include "Lemon.hpp"

class Lime: public Lemon {
    public:
        Lime(int const &vitamin = 2, std::string const &name = "lime");
        ~Lime();

    protected:
    private:
};

#endif /* !LIME_HPP_ */
