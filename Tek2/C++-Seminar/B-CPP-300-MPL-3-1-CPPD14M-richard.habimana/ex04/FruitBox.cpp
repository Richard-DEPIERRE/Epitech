/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD14M-richard.habimana
** File description:
** FruitBox
*/

#include "FruitBox.hpp"

FruitBox::FruitBox(int size): _max_size((size <= 0) ? 0 : size), _fruit(nullptr)
{
}

FruitBox::~FruitBox()
{
}

int FruitBox::nbFruits() const
{
    if (_fruit == nullptr)
        return (0);
    int count = 0;
    for (FruitNode *ptr = _fruit; ptr; ptr = ptr->next)
        count++;
    return (count);
}

bool FruitBox::putFruit(Fruit *f)
{
    if (_max_size == 0)
        return (false);
    if (f == nullptr)
        return (false);
    if (_fruit == nullptr) {
        _fruit = new FruitNode;
        _fruit->fruit = f;
        _fruit->next = nullptr;
        return (true);
    }
    FruitNode *ptr = _fruit;
    int count = 0;
    if (ptr->fruit == f || ++count >= _max_size)
            return (false);
    for (; ptr->next; ptr = ptr->next)
        if (ptr->fruit == f || ++count >= _max_size)
            return (false);
    if (count >= _max_size)
        return (false);
    ptr->next = new FruitNode;
    ptr->next->fruit = f;
    ptr->next->next = nullptr;
    return (true);
}

Fruit *FruitBox::pickFruit()
{
    if (_fruit == nullptr)
        return nullptr;
    FruitNode *old_fruit = _fruit;
    _fruit = _fruit->next;
    Fruit *res = old_fruit->fruit;
    delete old_fruit;
    return (res);
}