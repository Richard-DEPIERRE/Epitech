/*
** EPITECH PROJECT, 2021
** main.cpp
** File description:
** main
*/

#ifndef KOALANURSE_H_
    #define KOALANURSE_H_

    #include <iostream>
    #include <string>
    #include "SickKoala.hpp"

    class KoalaNurse {
        private:
            int id;
            int check;
        public:
            KoalaNurse(int);
            ~KoalaNurse();
            void giveDrug(std::string, SickKoala *);
            std::string readReport(std::string);
            void timeCheck();
            int getId();
    };

#endif /* !KOALANURSE_H_ */