/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush2-richard.habimana
** File description:
** Box
*/

#ifndef BOX_HPP_
#define BOX_HPP_

#include <fstream>
#include <string>
#include <iostream>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <list>
#include <array>
#include "Wrap.hpp"
#include "Object.hpp"

class Box: public Wrap {
    public:
        Box();
        ~Box();
        Box(Object obj);
        Toy *getToy() const;
        void setToy(Toy *obj);
        bool wrapMeThat(Object *obj);
        Object *openMe();
        void closeMe();
        virtual Toy *returnInside() final {
            return _toy;
        }
    protected:
        Toy *_toy = nullptr;
        bool _isOpen = true;

    private:
};

#endif /* !BOX_HPP_ */
