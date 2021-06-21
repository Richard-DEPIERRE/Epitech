/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD16-richard.habimana
** File description:
** DomesticKoala
*/

#ifndef DOMESTICKOALA_HPP_
#define DOMESTICKOALA_HPP_

#include <fstream>
#include <string>
#include <iostream>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include "KoalaAction.hpp"



using methodPointer_t = void (KoalaAction::*)(const std::string &);
class DomesticKoala {
    public:
        ~DomesticKoala();
        DomesticKoala(KoalaAction &);
        DomesticKoala(const DomesticKoala &);
        DomesticKoala &operator=(const DomesticKoala&);
        const std::vector<methodPointer_t> *getActions() const{return _vectors;};
        void learnAction(unsigned char command , methodPointer_t action);
        void unlearnAction(unsigned char command);
        void doAction(unsigned char command, const std::string &param);
        void setKoalaAction(KoalaAction &);

    protected:
    private:
        std::vector<methodPointer_t> *_vectors;
        std::vector<char> *_command;
        KoalaAction _action;
};

#endif /* !DOMESTICKOALA_HPP_ */
