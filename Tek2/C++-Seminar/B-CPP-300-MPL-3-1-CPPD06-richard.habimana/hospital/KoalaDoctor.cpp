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
#include "KoalaDoctor.hpp"
#include "KoalaNurse.hpp"

KoalaDoctor::KoalaDoctor(std::string str): name(str), check(0)
{
    std::cout << "Dr." << str << ": I'm Dr." << str << "! How do you kreog?" << std::endl;
}

KoalaDoctor::~KoalaDoctor()
{
}

void KoalaDoctor::diagnose(SickKoala *koala)
{
    std::string file;
    std::ofstream stream;
    int i = random() % 5;

    std::cout << "Dr." << this->name << ": So what's goerking you Mr." << koala->getName() << "?" << std::endl;
    koala->poke();
    file = koala->getName() + ".report";
    stream.open(file);
    if (i == 0)
        stream << "Mars";
    else if (i == 1)
        stream << "Kinder";
    else if (i == 2)
        stream << "Crunch";
    else if (i == 3)
        stream << "Maroilles";
    else if (i == 4)
        stream << "Eucalyptus leaf";
}

void KoalaDoctor::timeCheck()
{
    if (check == 0)
        std::cout << "Dr." << this->name << ": Time to get to work!" << std::endl;
    else
        std::cout << "Dr." << this->name << ": Time to go home to my eucalyptus forest!" << std::endl;
    check = (check == 0) ? 1 : 0;
}

std::string KoalaDoctor::getName()
{
    return (this->name);
}

// int		main()
// {
//   KoalaNurse    KoalaNurse(194) ;
//   SickKoala     SickKoala("JUanestpd");
//   KoalaDoctor	KoalaDoctor("House");
//   srandom(42);

//   KoalaDoctor.diagnose(&SickKoala);
//   KoalaDoctor.timeCheck();
//   return 0;
// }