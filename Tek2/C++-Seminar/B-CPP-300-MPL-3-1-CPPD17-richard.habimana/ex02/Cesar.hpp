/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD17-richard.habimana
** File description:
** Cesar
*/

#ifndef CESAR_HPP_
#define CESAR_HPP_

#include "IEncryptionMethod.hpp"
#include <string>
#include <iostream>

class Cesar : public IEncryptionMethod {
    public:
        Cesar();
        ~Cesar();
        void encryptChar(char plainchar);
        void decryptChar(char cipherchar);
        void reset();

    protected:
    private:
        int _shift;
};

#endif /* !CESAR_HPP_ */
