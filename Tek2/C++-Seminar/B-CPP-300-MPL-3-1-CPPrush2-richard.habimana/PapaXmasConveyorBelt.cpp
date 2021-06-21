/*
** EPITECH PROJECT, 2021
** Papa Xmas ConveyorBelt
** File description:
** file
*/

#include "PapaXmasConveyorBelt.hpp"

PapaXmasConveyorBelt::PapaXmasConveyorBelt(): IConveyorBelt()
{
    _is_empty = true;
    _object = nullptr;
}

PapaXmasConveyorBelt::~PapaXmasConveyorBelt()
{
}

bool PapaXmasConveyorBelt::setObject(Object *object)
{
    if (object == nullptr) {
        std::cerr << "Error setObject : The given object is NULL" << std::endl;
        return false;
    }
    _object = object;
    return true;
}

Object *PapaXmasConveyorBelt::Take()
{
    if (is_empty()) {
        std::cerr << "Error take : Conveyor Belt is empty" << std::endl;
        return nullptr;
    }
    if (dynamic_cast<Wrap *>(_object))
        std::cout << "whistles while working" << std::endl;
    Object *res = _object;
    _object = nullptr;
    return res;
}

bool PapaXmasConveyorBelt::Put(Object *object)
{
    if (!is_empty()) {
        std::cerr << "Error put : Conveyor Belt is not empty" << std::endl;
        return false;
    }
    if (!setObject(object))
        return false;
    object = nullptr;
    _is_empty = false;
    return true;
}

bool PapaXmasConveyorBelt::In()
{
    if (!is_empty()) {
        std::cerr << "Error In : Conveyor Belt is not empty" << std::endl;
        return false;
    }
    if ((std::rand()/((RAND_MAX + 1u) / 2)) == 0) {
        _object = new Box;
    } else
        _object = new GiftPaper;
    return true;
}

bool PapaXmasConveyorBelt::Out()
{
    if (is_empty()) {
        std::cerr << "Error Out : Conveyor Belt is empty" << std::endl;
        return false;
    }
    addXML(this->_object);
    _is_empty = true;
    _object = nullptr;
    return true;
}

void PapaXmasConveyorBelt::addXML(Object *obj)
{
    static int tmp = 0;
    std::ofstream outfile;
    outfile.open("Gift1.xml", std::ios::out | std::ios::app);
    if (tmp == 0) {
        GiftPaper *gift = (GiftPaper *)(obj);
        std::cout << gift->returnInside()->returnInside()->getTitle() << std::endl;
        outfile << "\t\t<gifts.name>" << gift->returnInside()->returnInside()->getTitle() << "</gifts.name>\n\t</item>\n";
        tmp += 1;
    } else {
        GiftPaper *gift = (GiftPaper *)(obj);
        std::cout << gift->returnInside()->returnInside()->getTitle() << std::endl;
        outfile << "\t<item>\n\t\t<gifts.name>" << gift->returnInside()->returnInside()->getTitle() << "</gifts.name>\n\t</item>\n";
    }
    outfile.close();
}

PapaXmasConveyorBelt *createConveyorBelt()
{
    PapaXmasConveyorBelt *Cb = new PapaXmasConveyorBelt;
    return Cb;
}