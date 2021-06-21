/*
** EPITECH PROJECT, 2021
** main.cpp
** File description:
** main
*/

#ifndef NURSEKOALALIST_HPP_
    #define NURSEKOALALIST_HPP_

    #include "KoalaNurse.hpp"

    class KoalaNurseList {
        private:
            KoalaNurse *nurse;
            KoalaNurseList *next;
        public:
            KoalaNurseList(KoalaNurse *nurse);
            ~KoalaNurseList();
            bool isEnd();
            void append(KoalaNurseList *new_node);
            KoalaNurse *getFromID(int id);
            KoalaNurseList *remove(KoalaNurseList *new_node);
            KoalaNurseList *removeFromID(int id);
            KoalaNurse *getContent();
            KoalaNurseList *getNext();
            void dump();
    };
#endif /* !NURSEKOALALIST_HPP_ */