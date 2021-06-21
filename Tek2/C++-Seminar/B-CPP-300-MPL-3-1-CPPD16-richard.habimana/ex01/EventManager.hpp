/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD16-richard.habimana
** File description:
** EventManager
*/

#ifndef EVENTMANAGER_HPP_
#define EVENTMANAGER_HPP_

#include <fstream>
#include <string>
#include <iostream>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <list>
#include <algorithm>
#include "Event.hpp"

class EventManager {
    public:
        EventManager();
        ~EventManager();
        EventManager(EventManager const &other);
        EventManager &operator=(EventManager const &rhs);
        void addEvent(const Event &e);
        void removeEventsAt(unsigned int time);
        void dumpEvents() const;
        void dumpEventAt(unsigned int time) const;
        void addTime(unsigned int time);
        void addEventList(const std::list<Event> &events);

    protected:
    private:
        std::list<Event> _events;
        unsigned int _time;
};

#endif /* !EVENTMANAGER_HPP_ */
