/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share
** File description:
** Santa
*/

#include "../PapaXmasElf.hpp"
#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char **av)
{
    if (ac <= 1) {
        std::cerr << "Please input some files for santa !" << std::endl;
        return (84);
    }
    for (int i = 1; i < ac; i++) {
        std::ifstream newFile(av[i],std::ios::in);
        if (newFile.is_open()) {
            std::cout << "open Gift: " << av[i] << "\n\n";
            std::string str;
            while(std::getline(newFile, str)) {
                if (str.find("<gifts.name") != std::string::npos) {
                    std::string new_string = str.substr(str.find("<gifts.name") + 16, str.find("</gifts.name>") - 18);
                    Toy *new_toy;
                    if (new_string.substr(0, new_string.find("\">")) == "Teddy") {
                        std::string name = new_string.substr(new_string.find("\">") + 2, new_string.length());
                        new_toy = new Teddy(name);
                    } else {
                        std::string name = new_string.substr(new_string.find("\">") + 2, new_string.length());
                        new_toy = new LittlePony(name);
                    }
                    Box *new_box = new Box;
                    GiftPaper *new_giftpaper = new GiftPaper;
                    new_toy->isTaken();
                    new_box->wrapMeThat(new_toy);
                    new_giftpaper->wrapMeThat(new_box);
                }
            }
            newFile.close();
        }
        std::cout << "\n\n";
    }
}
