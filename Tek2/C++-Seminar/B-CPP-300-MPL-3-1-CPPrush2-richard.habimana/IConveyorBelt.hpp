/*
** EPITECH PROJECT, 2021
** IConveyorBelt
** File description:
** Header File
*/

#ifndef ICONVEYORBELT_H_
#define ICONVEYORBELT_H_

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
#include "Wrap.hpp"

class IConveyorBelt {
    public:
        IConveyorBelt();
        virtual ~IConveyorBelt();
        virtual Object *Take() = 0;
        virtual bool Put(Object *) = 0;
        virtual bool In() = 0;
        virtual bool Out(const std::string filename, int *loop) = 0;

    protected:
        Object *_object;
        bool _is_empty;
    private:
};

#endif /* !ICONVEYORBELT_H_ */