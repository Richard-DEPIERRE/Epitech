/*
** EPITECH PROJECT, 2021
** main.cpp
** File description:
** main
*/

#ifndef SICKKOALALIST_HPP_
    #define SICKKOALALIST_HPP_

    #include "SickKoala.hpp"

    class SickKoalaList {
        private:
            SickKoala *sick;
            SickKoalaList *next;
        public:
            SickKoalaList(SickKoala *sick);
            ~SickKoalaList();
            bool isEnd();
            void append(SickKoalaList *new_node);
            SickKoala *getFromName(std::string str);
            SickKoalaList *remove(SickKoalaList *new_node);
            SickKoalaList *removeFromName(std::string str);
            SickKoala *getContent();
            SickKoalaList *getNext();
            void dump();
    };
#endif /* !SICKKOALALIST_HPP_ */