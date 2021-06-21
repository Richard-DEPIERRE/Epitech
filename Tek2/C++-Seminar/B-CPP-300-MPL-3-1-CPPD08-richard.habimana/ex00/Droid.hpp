/*
** EPITECH PROJECT, 2021
** main.cpp
** File description:
** main
*/

#ifndef BORG_H_
    #define BORG_H_

    #include <fstream>
    #include <string>
    #include <iostream>
    #include <cstring>
    #include <sstream>
    #include <algorithm>
    #include <iomanip>

    class Droid {
        private:
            std::string _serial;
            size_t _energy;
            const size_t _attack;
            const size_t _toughness;
            std::string *_status;
        public:
            Droid(std::string serial = "");
            Droid(const Droid &new_droid);
            ~Droid();
            //get
            std::string getId() const;
            size_t getEnergy() const;
            size_t getAttack() const;
            size_t getToughness() const;
            std::string *getStatus() const;
            //set
            void setId(std::string string);
            void setEnergy(size_t energy);
            void setStatus(std::string *string);
            Droid &operator=(Droid const & droid);
            Droid &operator<<(size_t &energy);
            bool operator==(const Droid &new_droid) const;
            bool operator!=(const Droid &new_droid) const;
    };
    std::ostream &operator<<(std::ostream &os, const Droid &new_droid);
#endif