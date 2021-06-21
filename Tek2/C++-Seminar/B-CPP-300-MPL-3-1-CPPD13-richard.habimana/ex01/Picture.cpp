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

Picture::Picture(const Picture &pic): data(pic.data)
{
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
            this->data += (str + "\n");
        return (true);
    } else {
        this->data = "ERROR";
        return (false);
    }
}

Picture &Picture::operator=(Picture const pic)
{
    this->data = pic.data;
    return (*this);
}