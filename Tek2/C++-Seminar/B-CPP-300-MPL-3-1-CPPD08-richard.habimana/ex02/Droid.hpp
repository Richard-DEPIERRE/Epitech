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
    #include "DroidMemory.hpp"

    class Droid {
        private:
            std::string _serial;
            size_t _energy;
            const size_t _attack;
            const size_t _toughness;
            std::string *_status;
            DroidMemory *BattleData;
        public:
            Droid(std::string serial);
            Droid(const Droid &new_droid);
            ~Droid();
            //get
            std::string getId() const;
            size_t getEnergy() const;
            size_t getAttack() const;
            size_t getToughness() const;
            std::string *getStatus() const;
            DroidMemory *getBattleData() const;
            //set
            void setId(const std::string string);
            void setEnergy(const size_t energy);
            void setStatus(const std::string *string);
            void setBattleData(const DroidMemory *droid);
            //operator
            Droid &operator=(Droid const & droid);
            Droid &operator<<(size_t &energy);
            bool operator==(const Droid &new_droid) const;
            bool operator!=(const Droid &new_droid) const;
            bool operator()(const std::string *name, size_t cost);
    };
    std::ostream &operator<<(std::ostream &os, const Droid &new_droid);
#endif