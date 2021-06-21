/*
** EPITECH PROJECT, 2021
** Piscine_Cpp
** File description:
** ToyStory
*/

#include "ToyStory.hpp"

ToyStory::ToyStory()
{
}

ToyStory::~ToyStory()
{
}

bool ToyStory::tellMeAStory(std::string const &filename, Toy &toy1, bool (Toy::*funct1)(std::string const &message)const, Toy &toy2, bool (Toy::*funct2)(std::string const &message)const)
{
    std::cout << toy1.getAscii() << std::endl;
    std::cout << toy2.getAscii() << std::endl;
    std::ifstream newFile(filename);
    if (newFile.is_open()) {
        std::string str;
        bool is_one = true;
        while(std::getline(newFile, str)){
            if (str.find("picture") == 0) {
                if (is_one) {
                    toy1.setAscii(str.substr(str.find("picture:") + 8));
                    std::cout << toy1.getAscii() << std::endl;
                } else {
                    toy2.setAscii(str.substr(str.find("picture:") + 8));
                    std::cout << toy2.getAscii() << std::endl;
                }
            } else {
                if (is_one)
                    (toy1.*funct1)(str);
                else
                    (toy2.*funct2)(str);
                is_one = !is_one;
            }
        }
    } else {
        std::cerr << "Can\'t open the file" << std::endl;
        return false;
    }
    return (true);
}