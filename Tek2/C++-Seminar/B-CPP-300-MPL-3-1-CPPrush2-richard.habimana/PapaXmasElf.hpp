/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush2-richard.habimana
** File description:
** PapaXmasElf
*/

#ifndef PAPAXMASELF_HPP_
#define PAPAXMASELF_HPP_

#include <fstream>
#include <string>
#include <iostream>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <list>
#include <array>
#include "IElf.hpp"
#include "Wrap.hpp"

class PapaXmasElf: public IElf {
    public:
        PapaXmasElf();
        virtual ~PapaXmasElf();
        void Take(workstation ws, int i = 0);
        void Put(workstation ws, Object *object);
        void In();
        void Look(const std::string filename);
        int LookToy();
        int LookBox();
        int LookGiftPaper();
        int LookFullBox();
        int LookFullGift();
        void PrintTable();
        void startToWork();
    private:
        int _loop;
    protected:
};

#endif /* !PAPAXMASELF_HPP_ */
