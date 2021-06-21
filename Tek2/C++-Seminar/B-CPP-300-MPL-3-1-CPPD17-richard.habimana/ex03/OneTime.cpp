/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD17-richard.habimana
** File description:
** OneTime
*/

#include "OneTime.hpp"

OneTime::OneTime(std::string str): _str(str), _shift(0)
{
}

OneTime::~OneTime()
{
}

void OneTime::encryptChar(char plainchar)
{
    if (isalpha(plainchar)) {
        int a = (plainchar >= 'a') ? 97 : 65;
        int b = (_str[_shift] >= 'a') ? 97 : 65;
        std::cout << static_cast<char>(((plainchar - a + (_str[_shift] - b)) % 26) + a);
    } else
        std::cout << plainchar;
    _shift = (++_shift) % _str.size();
}

void OneTime::decryptChar(char cipherchar)
{
    if (isalpha(cipherchar)) {
        int a = (cipherchar >= 'a') ? 122 : 90;
        int b = (_str[_shift] >= 'a') ? 97 : 65;
        std::cout << static_cast<char>(((cipherchar - a - (_str[_shift] - b)) % 26) + a);
    } else
        std::cout << cipherchar;
    _shift = (++_shift) % _str.size();
}

void OneTime::reset()
{
    _shift = 0;
}