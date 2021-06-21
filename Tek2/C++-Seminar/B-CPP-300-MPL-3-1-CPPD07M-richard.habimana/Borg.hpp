/*
** EPITECH PROJECT, 2021
** main.cpp
** File description:
** main
*/


#ifndef BORG_H_
    #define BORG_H_

    namespace Borg {
        class Ship;
    }

    #include "Federation.hpp"

    class Borg::Ship{
        private:
            int _side;
            short _maxWarp;
            WarpSystem::Core *_core;
            Destination _location;
            Destination _home;
            int _shield;
            int _weaponFrequency;
            short _repair;
        public:
            Ship(int weaponFrequency = 20, short repair = 3);
            ~Ship();
            void setupCore(WarpSystem::Core *core);
            void checkCore();
            bool move(int warp, Destination d);
            bool move(int warp);
            bool move(Destination d);
            bool move();
            int getShield();
            void setShield(int shield);
            int getWeaponFrequency();
            void setWeaponFrequency(int frequency);
            short getRepair();
            void setRepair(short repair);
            void fire(Federation::Starfleet::Ship *target);
            void fire(Federation::Ship *target);
            void repair();
    };

#endif /* !BORG_H_ */