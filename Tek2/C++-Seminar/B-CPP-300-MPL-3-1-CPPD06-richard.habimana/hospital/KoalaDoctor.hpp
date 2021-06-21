/*
** EPITECH PROJECT, 2021
** main.cpp
** File description:
** main
*/

#ifndef KOALADOCTOR_H_
    #define KOALADOCTOR_H_

    #include <iostream>
    #include <string>
    #include "SickKoala.hpp"

    class KoalaDoctor {
        private:
            std::string name;
            int check;
        public:
            KoalaDoctor(std::string);
            ~KoalaDoctor();
            void diagnose(SickKoala *);
            void timeCheck();
            std::string getName();
    };

#endif /* !KOALANURSE_H_ */