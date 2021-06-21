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
#include "SickKoala.hpp"

SickKoala::SickKoala(std::string str): name(str)
{
}

SickKoala::~SickKoala()
{
    std::cout << "Mr." << this->name << ": Kreooogg!! I'm cuuuured!" << std::endl;
}


void SickKoala::poke()
{
    std::cout << "Mr." << this->name << ": Gooeeeeerrk!!" << std::endl;
}

bool SickKoala::takeDrug(std::string str)
{
    if (str == "Mars") {
        std::cout << "Mr." << this->name << ": Mars, and it kreogs!" << std::endl;
        return(true);
    } else if (str == "Kinder") {
        std::cout << "Mr." << this->name << ": There is a toy inside!" << std::endl;
        return(true);
    }
    std::cout << "Mr." << this->name << ": Goerkreog!" << std::endl;
    return(false);
}

void SickKoala::overDrive(std::string str)
{
    while(str.find("Kreog!") != std::string::npos)
        str.replace(str.find("Kreog!"), 6, "1337!");
    std::cout << "Mr." << this->name << ": " << str << std::endl;
}

std::string SickKoala::getName()
{
    return (this->name);
}

// int main()
// {
//   SickKoala SickKoala("Koko") ;

//   SickKoala.poke();
//   SickKoala.takeDrug("Mars");
//   SickKoala.overDrive("Kreog ! Ca boume ?");
//   return 0;
// }