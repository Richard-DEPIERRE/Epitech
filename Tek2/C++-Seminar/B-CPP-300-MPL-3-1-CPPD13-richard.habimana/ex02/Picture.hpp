/*
** EPITECH PROJECT, 2021
** Piscine_Cpp
** File description:
** Picture
*/

#ifndef PICTURE_HPP_
#define PICTURE_HPP_

#include <fstream>
#include <string>
#include <iostream>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <iomanip>

class Picture {
    public:
        Picture(const std::string &file = "");
        ~Picture();

        //Functions
        bool getPictureFromFile(const std::string &file);

        //Variables
        std::string data;

        //Canonical
        Picture &operator=(Picture const pic);

    protected:
    private:
};

#endif /* !PICTURE_HPP_ */
