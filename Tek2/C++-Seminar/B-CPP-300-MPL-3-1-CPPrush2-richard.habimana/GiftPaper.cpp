/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush2-richard.habimana
** File description:
** GiftPaper
*/

#include "GiftPaper.hpp"
#include "Object.hpp"

GiftPaper::GiftPaper()
{
    _type = "GiftPaper";
}

GiftPaper::GiftPaper(Object obj)
{
    _box = nullptr;
    _isOpen = true;
}

GiftPaper::~GiftPaper()
{
}

void GiftPaper::setBox(Box *box)
{
    this->_box = box;
}

bool GiftPaper::wrapMeThat(Object *obj)
{
    Box *box = dynamic_cast <Box *>(obj);
    if (box) {
        Toy *toy =  dynamic_cast <Toy *>(box->getToy());
        if (toy) {
            if (!this->_box) {
                this->_isOpen = false;
                this->setBox(box);
                std::cout << "Wrapping the Box with the " << box->returnInside()->getType() <<" in the GiftPaper" << std::endl;
                return (true);
            } else {
                std::cerr << "In GiftPaper : The box cannot be put in the GiftPaper." << std::endl;
                return (false);
            }
        } else {
            std::cerr << "In GiftPaper : The box does not contain a toy." << std::endl;
            return (false);
        }
    } else {
        std::cerr << "In GiftPaper : The object is not a box." << std::endl;
    }
    return (false);
}

Object *GiftPaper::openMe()
{
    Wrap *tmp;

    if (!this->_box) {
        std::cerr << "In GiftPaper : The GiftPaper does not contain box" << std::endl;
        return (nullptr);
    }
    if (this->_isOpen == true) {
        std::cerr << "In GiftPaper : The GiftPaper is already open" << std::endl;
        return (nullptr);
    }
    tmp = this->_box;
    this->_box = nullptr;
    this->_isOpen = true;
    return (tmp);
}

void GiftPaper::closeMe()
{
    if (this->_isOpen == false) {
        std::cerr << "In GiftPaper : The GiftPaper is already closed." << std::endl;
        return;
    }
    this->_isOpen = false;
}