/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush2-richard.habimana
** File description:
** Itable
*/

#ifndef ITABLE_HPP_
#define ITABLE_HPP_

#include <fstream>
#include <string>
#include <iostream>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <list>
#include <array>
#include "Object.hpp"

typedef struct objects_s {
    std::array<std::string, 11> _names;
    std::array<Object *, 11> _objects;
} objects_t;

class ITable {
    public:
        ITable();
        virtual ~ITable();
        virtual Object *Take(int i = 0) = 0;
        virtual bool Put(Object *) = 0;
        virtual std::array<std::string, 11> look() const = 0;
        virtual void MakeNull(int i) = 0;
        virtual void FullBox(int i) = 0;
        virtual void FullGift(int i) = 0;
    protected:
        objects_t _objects;
        size_t _max_capacity;
    private:
};

#endif /* !ITABLE_HPP_ */