/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD15-richard.habimana
** File description:
** ex04
*/

#ifndef EX04_HPP_
#define EX04_HPP_

#include <stdio.h>
#include <string.h>
#include <iostream>

template<typename T>
bool equal(T const &a, T const &b)
{
    return (a == b);
}

template<typename T>
class Tester {
    public:
        bool equal(T const &a, T const &b);
};

#endif /* !EX04_HPP_ */
