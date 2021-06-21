/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD10-richard.habimana
** File description:
** Squad
*/

#include "Squad.hpp"

Squad::Squad()
{
}

Squad::~Squad()
{
    for (ISpaceMarine *tmp : _units)
        delete tmp;
}

Squad::Squad(const Squad &new_squad)
{
    for (ISpaceMarine *tmp : _units)
        delete tmp;
    _units.clear();
    for (ISpaceMarine *tmp : new_squad._units)
        _units.push_back(tmp->clone());
}

int Squad::getCount() const
{
    return _units.size();
}

ISpaceMarine* Squad::getUnit(int iteration)
{
    int a = 0;
    for (ISpaceMarine *tmp : _units) {
        if (a == iteration)
            return (tmp);
        a++;
    }
    return (nullptr);
}

int Squad::push(ISpaceMarine *new_marine)
{
    if (!new_marine)
        return getCount();
    std::list<ISpaceMarine *>::iterator it = _units.begin();
    for (; it != _units.end(); it++)
        if (*it == new_marine)
            return getCount();
    _units.push_back(new_marine);
    return getCount();
}
