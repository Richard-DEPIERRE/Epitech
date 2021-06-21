/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD17-richard.habimana
** File description:
** Encryption
*/

#include "Encryption.hpp"

Encryption::Encryption(IEncryptionMethod& encryptionMethod, void (IEncryptionMethod::*funct)(char)): _encryptionMethod(encryptionMethod), _funct(funct)
{
}

Encryption::~Encryption()
{
}

void Encryption::operator()(char character)
{
    (_encryptionMethod.*_funct)(character);
}

void Encryption::encryptString(IEncryptionMethod &encryptionMethod , const std::string &toEncrypt)
{
    encryptionMethod.reset();
    std::for_each(toEncrypt.begin(), toEncrypt.end(), Encryption(encryptionMethod, &IEncryptionMethod::encryptChar));
    std::cout << std::endl;
}

void Encryption::decryptString(IEncryptionMethod& encryptionMethod , const std::string &toDecrypt)
{
    encryptionMethod.reset();
    std::for_each(toDecrypt.begin(), toDecrypt.end(), Encryption(encryptionMethod, &IEncryptionMethod::decryptChar));
    std::cout << std::endl;
}