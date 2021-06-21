/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush2-richard.habimana
** File description:
** PapaXmasTable
*/

#ifndef PAPAXMASTABLE_HPP_
#define PAPAXMASTABLE_HPP_

#include <fstream>
#include <string>
#include <iostream>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <list>
#include <array>
#include "ITable.hpp"
#include "Teddy.hpp"
#include "LittlePony.hpp"
#include "Box.hpp"
#include "GiftPaper.hpp"

typedef enum RandPop_e {
    PONY,
    TEDDY,
    BOX,
    GIFTPAPER
}RandPop;

class PapaXmasTableRand: public ITable {
    public:
        PapaXmasTableRand();
        virtual ~PapaXmasTableRand();
        Object *Take(int i = 0);
        bool Put(Object *objects);
        std::array<std::string, 11> look() const;
        void MakeNull(int i);
        void FullBox(int i);
        void FullGift(int i);
        void GetTitles();
        void WrapMe(int wrapping, int wrapped);
        Object *GetObject(int i);
        std::string GetTitle(int i);
    protected:
    private:
};

PapaXmasTableRand *createTableRand();

#endif /* !PAPAXMASTABLE_HPP_ */
