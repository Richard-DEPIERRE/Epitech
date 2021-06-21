/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD17-richard.habimana
** File description:
** Encryption
*/

#ifndef ENCRYPTION_HPP_
#define ENCRYPTION_HPP_

#include "IEncryptionMethod.hpp"
#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>

class Encryption {
    public:
        Encryption(IEncryptionMethod& encryptionMethod, void (IEncryptionMethod::*funct)(char));
        ~Encryption();
        void operator()(char);
        static void encryptString(IEncryptionMethod &encryptionMethod , const std::string &toEncrypt);
        static void decryptString(IEncryptionMethod& encryptionMethod , const std::string &toDecrypt);
    protected:
    private:
        IEncryptionMethod& _encryptionMethod;
        void (IEncryptionMethod::*_funct)(char);
};

#endif /* !ENCRYPTION_HPP_ */
