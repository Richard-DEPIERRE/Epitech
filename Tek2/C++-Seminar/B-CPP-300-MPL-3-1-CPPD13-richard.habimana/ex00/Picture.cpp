/*
** EPITECH PROJECT, 2021
** Piscine_Cpp
** File description:
** Picture
*/

#include "Picture.hpp"

Picture::Picture(const std::string &file)
{
    if (file == "")
        data = "";
    else {
        getPictureFromFile(file);
    }
}

Picture::~Picture()
{
}

bool Picture::getPictureFromFile(const std::string &file)
{
    this->data = "";
    std::ifstream newFile(file);
    if (newFile.is_open()) {
        std::string str;
        while(std::getline(newFile, str))
            data += (str + "\n");
        return (true);
    } else {
        data = "ERROR";
        return (false);
    }
}
