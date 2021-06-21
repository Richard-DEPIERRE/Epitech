/*
** EPITECH PROJECT, 2021
** main.cpp
** File description:
** main
*/

#ifndef HOSPITAL_HPP_
    #define HOSPITAL_HPP_

    #include "KoalaDoctorList.hpp"
    #include "KoalaNurseList.hpp"
    #include "SickKoalaList.hpp"

    class Hospital {
        private:
            KoalaDoctorList *doctors;
            KoalaNurseList *nurses;
            SickKoalaList *sicks;
            int nb_doctors;
            int nb_nurses;
            int nb_sicks;
        public:
            Hospital();
            ~Hospital();
            void addDoctor(KoalaDoctorList *new_doctor);
            void addSick(SickKoalaList *new_sick);
            void addNurse(KoalaNurseList *new_nurse);
            void run();
    };
#endif /* !HOSPITAL_HPP_ */