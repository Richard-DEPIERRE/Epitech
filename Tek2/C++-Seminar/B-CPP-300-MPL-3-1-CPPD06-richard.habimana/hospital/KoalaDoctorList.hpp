/*
** EPITECH PROJECT, 2021
** main.cpp
** File description:
** main
*/

#ifndef DOCTORKOALALIST_HPP_
    #define DOCTORKOALALIST_HPP_

    #include "KoalaDoctor.hpp"

    class KoalaDoctorList {
        private:
            KoalaDoctor *doctor;
            KoalaDoctorList *next;
        public:
            KoalaDoctorList(KoalaDoctor *doctor);
            ~KoalaDoctorList();
            bool isEnd();
            void append(KoalaDoctorList *new_node);
            KoalaDoctor *getFromName(std::string str);
            KoalaDoctorList *remove(KoalaDoctorList *new_node);
            KoalaDoctorList *removeFromName(std::string str);
            KoalaDoctor *getContent();
            KoalaDoctorList *getNext();
            void dump();
    };
#endif /* !DOCTORKOALALIST_HPP_ */