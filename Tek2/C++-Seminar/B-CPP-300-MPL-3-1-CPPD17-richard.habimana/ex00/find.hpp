/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD17-richard.habimana
** File description:
** find
*/

#ifndef FIND_HPP_
#define FIND_HPP_

#include <algorithm>

template<typename T>
typename T::iterator do_find(T &a, int size)
{
    return(std::find(a.begin(), a.end(), size));
}

#endif /* !FIND_HPP_ */
