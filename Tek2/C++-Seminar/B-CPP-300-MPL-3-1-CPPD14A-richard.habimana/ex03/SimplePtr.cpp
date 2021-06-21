/*
** EPITECH PROJECT, 2021
** Piscine_Cpp
** File description:
** SimplePtr
*/

#include "SimplePtr.hpp"

SimplePtr::SimplePtr(BaseComponent *rawPtr): _rawPtr(rawPtr)
{
}

SimplePtr::~SimplePtr()
{
    delete _rawPtr;
}

BaseComponent *SimplePtr::get() const
{
    return _rawPtr;
}

SimplePtr::SimplePtr(SimplePtr const &simple)
{
}

SimplePtr &SimplePtr::operator=(SimplePtr const &)
{
    return (*this);
}