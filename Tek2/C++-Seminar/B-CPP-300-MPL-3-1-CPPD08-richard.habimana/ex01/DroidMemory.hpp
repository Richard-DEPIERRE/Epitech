/*
** EPITECH PROJECT, 2021
** main.cpp
** File description:
** main
*/

#ifndef DROIDMEMORY_H_
    #define DROIDMEMORY_H_

    #include <fstream>
    #include <string>
    #include <iostream>
    #include <cstring>
    #include <sstream>
    #include <algorithm>
    #include <iomanip>

    class DroidMemory {
        private:
            size_t _fingerprint;
            size_t _exp;
        public:
            DroidMemory();
            ~DroidMemory();
            size_t getFingerprint() const;
            size_t getExp() const;
            void setFingerprint(size_t fingerprint);
            void setExp(size_t exp);
            DroidMemory &operator<<(const DroidMemory &new_droid);
            DroidMemory &operator>>(DroidMemory &new_droid);
            DroidMemory &operator+=(const DroidMemory &new_droid);
            DroidMemory &operator+=(const size_t new_exp);
            DroidMemory &operator+(const DroidMemory &new_droid);
            DroidMemory &operator+(const size_t &new_exp);
    };
    std::ostream &operator<<(std::ostream &os, const DroidMemory &new_droid);
#endif