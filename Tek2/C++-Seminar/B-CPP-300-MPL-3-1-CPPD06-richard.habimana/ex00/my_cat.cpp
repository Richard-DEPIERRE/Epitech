/*
** EPITECH PROJECT, 2021
** main.cpp
** File description:
** main
*/

#include <fstream>
#include <string>
#include <iostream>

int check_errors(int ac)
{
    if (ac <= 1) {
        std::cerr << "my_cat: Usage: ./my_cat file [...]" << std::endl;
        return (84);
    }
    return (0);
}

int my_cat(int ac, char **av)
{
    char file_get = 0;

    if (check_errors(ac) == 84)
        return (84);
    for (int i = 1; i < ac; i++) {
        std::ifstream file(av[i]);
        if (!file.is_open())
            std::cerr << "my_cat: " << av[i] << ": No such file or directory" << std::endl;
        else {
            file_get = file.get();
            while (file.good()) {
                std::cout << file_get;
                file_get = file.get();
            }
            file.close();
        }
    }
    return (0);
}