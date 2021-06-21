/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD16-richard.habimana
** File description:
** Event
*/

#include "Event.hpp"

Event::Event(): _event(""), _time(0)
{
}

Event::Event(unsigned int time, const std::string &event): _event(event), _time(time)
{
}

Event::~Event()
{
}

Event::Event(const Event &other): _event(other.getEvent()), _time(other.getTime())
{
}

Event &Event::operator=(const Event &rhs)
{
    _event = rhs.getEvent();
    _time = rhs.getTime();
    return (*this);
}

