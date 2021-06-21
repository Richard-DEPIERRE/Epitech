/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD17-richard.habimana
** File description:
** OneTime
*/

#ifndef ONETIME_HPP_
#define ONETIME_HPP_

#include "IEncryptionMethod.hpp"
#include <string>
#include <iostream>

class OneTime : public IEncryptionMethod {
    public:
        OneTime(std::string str);
        ~OneTime();
        void encryptChar(char plainchar);
        void decryptChar(char cipherchar);
        void reset();

    protected:
    private:
        std::string _str;
        int _shift;
};

#endif /* !ONETIME_HPP_ */
