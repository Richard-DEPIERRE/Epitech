/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush2-richard.habimana
** File description:
** IElf
*/

#ifndef IELF_HPP_
#define IELF_HPP_

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
#include "PapaXmasConveyorBeltRand.hpp"
#include "PapaXmasTableRand.hpp"

typedef enum workstation_e {
    TABLE,
    CONVEYORBELT
}workstation;

class IElf {
    public:
        IElf();
        virtual ~IElf();
        virtual void Take(workstation ws, int i = 0) = 0;
        virtual void Put(workstation ws, Object *object) = 0;
        virtual void In() = 0;
        virtual void Look(const std::string filename) = 0;
    protected:
        Object *_hand;
        PapaXmasTableRand *_table;
        PapaXmasConveyorBeltRand *_conveyorBelt;
    private:
};

#endif /* !IELF_HPP_ */
