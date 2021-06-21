/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD16-richard.habimana
** File description:
** Event
*/

#ifndef EVENT_HPP_
#define EVENT_HPP_

#include <fstream>
#include <string>
#include <iostream>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <vector>

class Event {
    public:
        Event();
        Event(unsigned int time, const std::string &event);
        ~Event();
        Event(const Event &other);
        Event &operator=(const Event &rhs);
        unsigned int getTime() const{return _time;};
        const std::string &getEvent() const{return _event;};
        void setTime(unsigned int time){_time = time;};
        void setEvent(const std::string &event){_event = event;};

    protected:
    private:
        std::string _event;
        unsigned int _time;
};

#endif /* !EVENT_HPP_ */
