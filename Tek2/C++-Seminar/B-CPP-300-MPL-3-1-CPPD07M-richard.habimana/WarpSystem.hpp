/*
** EPITECH PROJECT, 2021
** main.cpp
** File description:
** main
*/

#ifndef WARPSYSTEM_H_
    #define WARPSYSTEM_H_

    namespace WarpSystem {
        class QuantumReactor;
        class Core;
    }
    #include <fstream>
    #include <string>
    #include <iostream>
    #include <cstring>
    #include <sstream>
    #include <algorithm>
    #include <iomanip>

    class WarpSystem::QuantumReactor {
        private:
            bool _stability;
        public:
            QuantumReactor(bool stability = true);
            ~QuantumReactor();
            bool isStable();
            void setStability(bool stability);
    };
    class WarpSystem::Core {
        private:
            QuantumReactor *_coreReactor;
        public:
            Core(QuantumReactor *coreReactor);
            ~Core();
            QuantumReactor *checkReactor();
    };
#endif /* !WARPSYSTEM_H_ */