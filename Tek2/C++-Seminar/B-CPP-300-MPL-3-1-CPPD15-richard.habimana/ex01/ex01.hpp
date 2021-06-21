/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD15-richard.habimana
** File description:
** ex01
*/

#ifndef EX01_HPP_
#define EX01_HPP_
#include <stdio.h>
#include <string.h>

template<typename T>
int compare(T const &a, T const &b)
{
    if (a == b)
        return 0;
    if (a < b)
        return -1;
    return 1;
}
template<>
int compare<const char *>(const char * const &a, const char * const &b)
{
    if (strcmp(a, b) < 0)
        return -1;
    else if (strcmp(a, b) > 0)
        return 1;
    return 0;
}
#endif /* !EX01_HPP_ */
