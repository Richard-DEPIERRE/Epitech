/*
** EPITECH PROJECT, 2021
** main.cpp
** File description:
** main
*/

#include "DroidMemory.hpp"

DroidMemory::DroidMemory(): _exp(0), _fingerprint((size_t)random())
{
}

DroidMemory::~DroidMemory()
{
}

size_t DroidMemory::getFingerprint() const
{
    return (_fingerprint);
}

size_t DroidMemory::getExp() const
{
    return (_exp);
}

void DroidMemory::setFingerprint(size_t fingerprint)
{
    _fingerprint = fingerprint;
}
void DroidMemory::setExp(size_t exp)
{
    _exp = exp;
}

DroidMemory &DroidMemory::operator<<(const DroidMemory &new_droid)
{
    setExp(_exp + new_droid.getExp());
    setFingerprint(_fingerprint ^ new_droid.getFingerprint());
    return (*this);
}

DroidMemory &DroidMemory::operator>>(DroidMemory &new_droid)
{
    new_droid.setExp(_exp + new_droid.getExp());
    new_droid.setFingerprint(_fingerprint ^ new_droid.getFingerprint());
    return (*this);
}

DroidMemory &DroidMemory::operator+=(const DroidMemory &new_droid)
{
    setExp(_exp + new_droid.getExp());
    setFingerprint(_fingerprint ^ new_droid.getFingerprint());
    return (*this);
}

DroidMemory &DroidMemory::operator+=(const size_t new_exp)
{
    setExp(_exp + new_exp);
    setFingerprint(_fingerprint ^ new_exp);
    return (*this);
}

DroidMemory &DroidMemory::operator+(const DroidMemory &new_droid)
{
    DroidMemory *res = new DroidMemory();
    res->setExp(_exp + new_droid.getExp());
    res->setFingerprint(_fingerprint ^ new_droid.getFingerprint());
    return (*res);
}

DroidMemory &DroidMemory::operator+(const size_t &new_exp)
{
    DroidMemory *res = new DroidMemory();
    res->setExp(_exp + new_exp);
    res->setFingerprint(_fingerprint ^ new_exp);
    return (*res);
}

std::ostream &operator<<(std::ostream &os, const DroidMemory &new_droid)
{
    return(os << "DroidMemory '" << new_droid.getFingerprint() << "', " << new_droid.getExp());
}
