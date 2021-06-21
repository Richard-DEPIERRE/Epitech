/*
** EPITECH PROJECT, 2021
** main.cpp
** File description:
** main
*/

#include <fstream>
#include <string>
#include <iostream>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include "KoalaNurse.hpp"
#include "KoalaDoctor.hpp"

KoalaNurse::KoalaNurse(int id): id(id), check(0)
{
}

KoalaNurse::~KoalaNurse()
{
    std::cout << "Nurse " << this->id << ": Finally some rest!" << std::endl;
}

void KoalaNurse::giveDrug(std::string str, SickKoala *koala)
{
    koala->takeDrug(str);
}

std::string KoalaNurse::readReport(std::string str)
{
    std::string name;
    std::string drug;
    std::ifstream file;

    if (str.find_last_of(".") == std::string::npos)
        return("");
    if (str.substr(str.find_last_of(".")) != ".report")
        return ("");
    name = str.substr(0, str.find_last_of("."));
    file.open(str);
    if (!file.is_open())
        return ("");
    getline(file, drug);
    if (drug != "")
        std::cout << "Nurse " << this->id << ": Kreog! Mr." << name << " needs a " << drug << "!" << std::endl;
    return (drug);
}

void KoalaNurse::timeCheck()
{
    if (check == 0)
        std::cout << "Nurse " << this->id << ": Time to get to work!" << std::endl;
    else
        std::cout << "Nurse " << this->id << ": Time to go home to my eucalyptus forest!" << std::endl;
    check = (check == 0) ? 1 : 0;
}

int KoalaNurse::getId()
{
    return (this->id);
}

// int             main()
// {
//   KoalaNurse	KoalaNurse(194) ;
//   SickKoala	SickKoala("Koko");

//   KoalaNurse.timeCheck();
//   KoalaNurse.giveDrug("Mars", &SickKoala);
//   KoalaNurse.readReport("ef.report");
//   return 0;
// }