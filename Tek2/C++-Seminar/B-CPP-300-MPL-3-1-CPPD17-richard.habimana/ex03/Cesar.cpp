/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD17-richard.habimana
** File description:
** Cesar
*/

#include "Cesar.hpp"

Cesar::Cesar(): _shift(3)
{
}

Cesar::~Cesar()
{
}

void Cesar::encryptChar(char plainchar)
{
    if (isalpha(plainchar)) {
        int a = (plainchar >= 'a') ? 97 : 65;
        std::cout << static_cast<char>(((plainchar - a + _shift) % 26) + a);
    } else
        std::cout << plainchar;
    _shift = (++_shift) % 26;
}

void Cesar::decryptChar(char cipherchar)
{
    if (isalpha(cipherchar)) {
        int a = (cipherchar >= 'a') ? 122 : 90;
        std::cout << static_cast<char>(((cipherchar - a - _shift) % 26) + a);
    } else
        std::cout << cipherchar;
    _shift = (++_shift) % 26;
}

void Cesar::reset()
{
    _shift = 3;
}