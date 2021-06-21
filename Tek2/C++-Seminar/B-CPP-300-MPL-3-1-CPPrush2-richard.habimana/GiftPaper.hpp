/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush2-richard.habimana
** File description:
** GiftPaper
*/

#ifndef GIFTPAPER_HPP_
#define GIFTPAPER_HPP_

#include <fstream>
#include <string>
#include <iostream>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <list>
#include <array>
#include "Box.hpp"
#include "Object.hpp"
#include "Toy.hpp"

class GiftPaper: public Wrap {
    public:
        GiftPaper();
        ~GiftPaper();
        GiftPaper(Object obj);
        void setBox(Box *box);
        bool wrapMeThat(Object *obj);
        Object *openMe();
        void closeMe();
        Box *returnInside() {
            return _box;
        }
    protected:
        Box *_box = nullptr;
        bool _isOpen = true;
    private:
};

#endif /* !GIFTPAPER_HPP_ */
