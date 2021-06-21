/*
** EPITECH PROJECT, 2021
** main.cpp
** File description:
** main
*/

#ifndef SICKKOALA_H_
    #define SICKKOALA_H_

    #include <string>

    class SickKoala {
        private:
            std::string name;
        public:
            SickKoala(std::string);
            ~SickKoala();
            void poke();
            bool takeDrug(std::string);
            void overDrive(std::string);
            std::string getName();
    };

#endif /* !SICKKOALA_H_ */