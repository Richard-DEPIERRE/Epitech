/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD15-richard.habimana
** File description:
** ex02
*/

#ifndef EX02_HPP_
#define EX02_HPP_

#include <iostream>
#include <array>

template<typename T>
T const min(T const &a, T const &b)
{
    std::cout << "template min" << std::endl;
    if (a <= b)
        return a;
    else
        return b;
};

int min(int a, int b)
{
    std::cout << "non-template min" << std::endl;
    if (a <= b)
        return a;
    else
        return b;
};
template<typename T>
T const &templateMin(T const *arr, int size)
{
    T &minimum = const_cast<T&>(arr[0]);
    for (int i = 1; i < size; i++)
        minimum = min<T>(minimum, arr[i]);
    return minimum;
}

int nonTemplateMin(int const *arr, int size)
{
    int minimum = arr[0];
    for (int i = 1; i < size; i++)
        minimum = min(minimum, arr[i]);
    return minimum;
}
#endif /* !EX02_HPP_ */
