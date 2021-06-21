/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush2-richard.habimana
** File description:
** Box
*/

#include "Box.hpp"
#include "Toy.hpp"
#include "Teddy.hpp"
#include "GiftPaper.hpp"

Box::Box()
{
    _type = "Box";
}

Box::~Box()
{
}

Box::Box(Object obj)
{
    _toy = nullptr;
    _isOpen = true;
}

Toy *Box::getToy() const
{
    return (this->_toy);
}

void Box::setToy(Toy *toy)
{
    this->_toy = toy;
}

bool Box::wrapMeThat(Object *obj)
{
    Toy *toy = dynamic_cast <Toy *>(obj);
    if (toy) {
        if(this->_isOpen == true && !this->_toy) {
            setToy(toy);
            this->_isOpen = false;
            std::cout << "The toy '" << toy->getTitle() << "' is in the box!" << std::endl;
            return (true);
        } else {
            std::cerr << "In Box : The toy cannot be put in the box." << std::endl;
            return (false);
        }
    } else {
        std::cerr << "In Box : The object is not a toy." << std::endl;
    }
    return (false);
}

Object *Box::openMe()
{
    Toy *tmp;

    if (!this->_toy) {
        std::cerr << "In Box : The box does not contain toy" << std::endl;
        return (nullptr);
    }
    if (this->_isOpen == true) {
        std::cerr << "In Box : The box is already open" << std::endl;
        return (nullptr);
    }
    tmp = this->_toy;
    this->_toy = nullptr;
    this->_isOpen = true;
    return (tmp);
}

void Box::closeMe()
{
    if (this->_isOpen == false) {
        std::cerr << "In Box : The Box is already closed." << std::endl;
        return;
    }
    this->_isOpen = false;
}