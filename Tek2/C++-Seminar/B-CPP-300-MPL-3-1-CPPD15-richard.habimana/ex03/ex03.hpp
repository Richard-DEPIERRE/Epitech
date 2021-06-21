/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD15-richard.habimana
** File description:
** ex03
*/

#ifndef EX03_HPP_
#define EX03_HPP_

#include <stdio.h>
#include <string.h>
#include <iostream>

template<typename T>
void print(const T &elem)
{
    std::cout << elem << std::endl;
};

template<typename T>
void foreach(T const *arr, void func(const T &elem), int size)
{
    for (int i = 0; i < size; i++)
        func(arr[i]);
};


#endif /* !EX03_HPP_ */
