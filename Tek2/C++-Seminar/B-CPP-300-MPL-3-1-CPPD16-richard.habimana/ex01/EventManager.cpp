/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD16-richard.habimana
** File description:
** EventManager
*/

#include "EventManager.hpp"

EventManager::EventManager(): _time(0)
{
}

EventManager::~EventManager()
{
}

EventManager::EventManager(EventManager const &other): _events(other._events), _time(other._time)
{
}

EventManager &EventManager::operator=(EventManager const &rhs)
{
    _events = rhs._events;
    _time = rhs._time;
    return (*this);
}

void EventManager::addEvent(const Event &e)
{
    _events.push_back(e);
    _events.sort([](const Event &e1, const Event &e2) {return (e1.getTime() < e2.getTime());});
}

void EventManager::removeEventsAt(unsigned int time)
{
    _events.remove_if([time](Event e){return e.getTime() == time;});
    _events.sort([](const Event &e1, const Event &e2) {return (e1.getTime() < e2.getTime());});
}

void EventManager::dumpEvents() const
{
    for (Event e: _events)
        std::cout << e.getTime() << ": " << e.getEvent() << std::endl;
}

void EventManager::dumpEventAt(unsigned int time) const
{
    for (Event e: _events)
        if (e.getTime() == time)
            std::cout << e.getTime() << ": " << e.getEvent() << std::endl;
}

void EventManager::addTime(unsigned int time)
{
    unsigned int old_time = _time;
    _time += time;
    unsigned int new_time = _time;
    _events.remove_if([old_time, new_time](Event e){
        if (e.getTime() >= old_time && e.getTime() <= new_time)
            std::cout << e.getEvent() << std::endl;
        return (e.getTime() >= old_time && e.getTime() <= new_time);
    });
    _events.sort([](const Event &e1, const Event &e2) {return (e1.getTime() < e2.getTime());});
}

void EventManager::addEventList(const std::list<Event> &events)
{
    for (Event e: events) {
        if (e.getTime() > _time)
            _events.push_back(e);
    }
    _events.sort([](const Event &e1, const Event &e2) {return (e1.getTime() < e2.getTime());});
}
