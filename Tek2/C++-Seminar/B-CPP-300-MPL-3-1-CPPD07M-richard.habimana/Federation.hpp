/*
** EPITECH PROJECT, 2021
** main.cpp
** File description:
** main
*/

#ifndef FEDERATION_H_
    #define FEDERATION_H_

    namespace Federation {
        namespace Starfleet {
            class Captain;
            class Ensign;
            class Ship;
        }
        class Ship;
    }

    #include <fstream>
    #include <string>
    #include <iostream>
    #include <cstring>
    #include <sstream>
    #include <algorithm>
    #include <iomanip>
    #include "WarpSystem.hpp"
    #include "Destination.hpp"
    #include "Borg.hpp"

    class Federation::Starfleet::Captain {
        private:
            std::string _name;
            int _age;
        public:
            Captain(std::string name, int age = 25);
            ~Captain();
            std::string getName();
            int getAge();
            void setAge(int age);
    };
    class Federation::Starfleet::Ensign {
        private:
            std::string _name;
        public:
            Ensign(std::string name);
            ~Ensign();
    };
    class Federation::Starfleet::Ship {
        private:
            int _length;
            int _width;
            std::string _name;
            short _maxWarp;
            WarpSystem::Core *_core;
            Captain *_captain;
            Destination _location;
            Destination _home;
            int _shield;
            int _photonTorpedo;
        public:
            Ship(int length = 289, int width = 132, std::string name = "Entreprise", short maxWarp = 6, int torpedo = 0);
            ~Ship();
            void setupCore(WarpSystem::Core *core);
            void checkCore();
            void promote(Captain *captain);
            bool move(int warp, Destination d);
            bool move(int warp);
            bool move(Destination d);
            bool move();
            int getShield();
            void setShield(int shield);
            int getTorpedo();
            void setTorpedo(int torpedo);
            void fire(Borg::Ship *target);
            void fire(int torpedoes , Borg::Ship *target);
    };
    class Federation::Ship {
        private:
            int _length;
            int _width;
            std::string _name;
            short _maxWarp;
            WarpSystem::Core *_core;
            Destination _location;
            Destination _home;
        public:
            Ship(int length, int width, std::string name, short maxWarp = 1);
            ~Ship();
            void setupCore(WarpSystem::Core *core);
            void checkCore();
            bool move(int warp, Destination d);
            bool move(int warp);
            bool move(Destination d);
            bool move();
            WarpSystem::Core *getCore();
    };

#endif /* !FEDERATION_H_ */