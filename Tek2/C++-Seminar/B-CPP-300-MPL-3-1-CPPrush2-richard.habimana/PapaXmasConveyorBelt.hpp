/*
** EPITECH PROJECT, 2021
** Papa Xmas Conveyor Belt
** File description:
** Header file
*/

#ifndef PAPAXMAS_CB_H_
#define PAPAXMAS_CB_H_

#include <fstream>
#include <string>
#include <iostream>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <list>
#include <array>
#include "IConveyorBelt.hpp"
#include "Box.hpp"
#include "GiftPaper.hpp"

class PapaXmasConveyorBelt : public IConveyorBelt {
    public:
        PapaXmasConveyorBelt();
        virtual ~PapaXmasConveyorBelt();
        bool is_empty() {
            return _is_empty;
        }
        Object *getObject() {
            return _object;
        }
        bool setObject(Object *object);
        Object *Take();
        bool Put(Object *object);
        bool In();
        bool Out();
        void addXML(Object *obj);

    protected:
    private:
};

PapaXmasConveyorBelt *createConveyorBelt();

#endif /* !PAPAXMAS_CB_H_ */