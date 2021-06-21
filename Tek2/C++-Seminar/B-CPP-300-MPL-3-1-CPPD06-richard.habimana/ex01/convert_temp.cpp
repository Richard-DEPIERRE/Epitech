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

int my_convert_temp()
{
    std::string string;
    float temperature;
    std::string name;
    std::stringstream stream;

    std::getline(std::cin, string);
    stream << string;
    stream >> temperature;
    stream >> name;
    if (name == "Celsius") {
        temperature = (temperature * 9.0 / 5.0) + 32.0;
        std::cout <<  std::setw(16) << std::fixed << std::setprecision(3) << temperature << std::setw(16) << "Fahrenheit" << std::endl;
    } else {
        temperature = (temperature - 32.0) * 5.0 / 9.0;
        std::cout <<  std::setw(16) << std::fixed << std::setprecision(3) << temperature << std::setw(16) << "Celsius" << std::endl;
    }
    return (0);
}