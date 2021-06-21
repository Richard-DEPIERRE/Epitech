/*
** EPITECH PROJECT, 2021
** Piscine_Cpp
** File description:
** Toy
*/

#ifndef TOY_HPP_
#define TOY_HPP_

#include <fstream>
#include <string>
#include <iostream>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include "Picture.hpp"

class Toy {
    public:
        enum ToyType{
            BASIC_TOY,
            ALIEN,
            BUZZ,
            WOODY
        };
        class Error {
            public:
                enum ErrorType{
                    UNKNOWN,
                    PICTURE,
                    SPEAK
                };
                Error() {type = UNKNOWN;};
                std::string const what() const;
                std::string const where() const;
                ErrorType type;
            private:
        };
        Toy(Toy::ToyType = BASIC_TOY, const std::string &name = "toy", const std::string &filename = "");
        ~Toy();
        std::string getName() const{return _name;};
        void setName(const std::string &name) {_name = name;};
        Toy::ToyType getType() const{return _type;};
        bool setAscii(const std::string &filename);
        std::string getAscii() const{return _pic.data;};
        virtual bool speak(const std::string &statement) const;
        virtual bool speak_es(const std::string &statement);
        Toy &operator<<(const std::string &str);
        Toy::Error getLastError(){return _error;};

        //Canonical
        Toy &operator=(Toy const toy);
    protected:
        Toy::ToyType _type;
        std::string _name;
        Picture _pic;
        Error _error;
    private:
};

std::ostream &operator<<(std::ostream &os, const Toy &toy);

#endif /* !TOY_HPP_ */
