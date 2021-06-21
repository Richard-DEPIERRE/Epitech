/*
** EPITECH PROJECT, 2021
** Piscine_Cpp
** File description:
** RefPtr
*/

#include "RefPtr.hpp"

RefPtr::RefPtr(BaseComponent *rawPtr): _rawPtr(rawPtr)
{
}

RefPtr::RefPtr(): RefPtr(nullptr)
{
}

RefPtr::~RefPtr()
{
    delete _rawPtr;
}

RefPtr::RefPtr(RefPtr const &new_raw) : _rawPtr(new_raw._rawPtr)
{
}

RefPtr &RefPtr::operator=(RefPtr const &obj)
{
    _rawPtr = obj._rawPtr;
    return (*this);
}

BaseComponent *RefPtr::get() const
{
    return _rawPtr;
}