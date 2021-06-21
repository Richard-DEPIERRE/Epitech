/*
** EPITECH PROJECT, 2021
** Papa Xmas ConveyorBelt
** File description:
** file
*/

#include "PapaXmasConveyorBeltRand.hpp"

PapaXmasConveyorBeltRand::PapaXmasConveyorBeltRand(): IConveyorBelt()
{
    _is_empty = true;
    _object = nullptr;
}

PapaXmasConveyorBeltRand::~PapaXmasConveyorBeltRand()
{
}

bool PapaXmasConveyorBeltRand::setObject(Object *object)
{
    if (object == nullptr) {
        std::cerr << "Error setObject : The given object is NULL" << std::endl;
        return false;
    }
    _object = object;
    return true;
}

Object *PapaXmasConveyorBeltRand::Take()
{
    if (is_empty()) {
        std::cerr << "Error take : Conveyor Belt is empty" << std::endl;
        return nullptr;
    }
    if (dynamic_cast<Wrap *>(_object))
        std::cout << "whistles while working" << std::endl;
    Object *res = _object;
    _object = nullptr;
    _is_empty = true;
    return res;
}

bool PapaXmasConveyorBeltRand::Put(Object *object)
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

bool PapaXmasConveyorBeltRand::In()
{
    if (!is_empty()) {
        std::cerr << "Error In : Conveyor Belt is not empty" << std::endl;
        return false;
    }
    if ((std::rand()/((RAND_MAX + 1u) / 2)) == 0) {
        _object = new Box;
    } else
        _object = new GiftPaper;
    _is_empty = false;
    return true;
}

bool PapaXmasConveyorBeltRand::Out(std::string const filename, int *loop)
{
    if (is_empty()) {
        std::cerr << "Error Out : Conveyor Belt is empty" << std::endl;
        return false;
    }
    addXML(_object, filename, loop);
    _is_empty = true;
    _object = nullptr;
    return true;
}

void PapaXmasConveyorBeltRand::addXML(Object *object, std::string const filename, int *loop)
{
    std::ofstream outfile;
    outfile.open(filename, std::ios::out | std::ios::app);
    if ((*loop) == 0) {
        GiftPaper *gift = (GiftPaper *)(object);
        std::cout << gift->returnInside()->returnInside()->getTitle() << std::endl;
        outfile << "\t\t<gifts.name id=\"" << gift->returnInside()->returnInside()->getType() << "\">" << gift->returnInside()->returnInside()->getTitle() << "</gifts.name>\n\t</item>\n";
        (*loop) += 1;
    } else {
        GiftPaper *gift = (GiftPaper *)(object);
        std::cout << gift->returnInside()->returnInside()->getTitle() << std::endl;
        outfile << "\t<item>\n\t\t<gifts.name id=\"" << gift->returnInside()->returnInside()->getType() << "\">" << gift->returnInside()->returnInside()->getTitle() << "</gifts.name>\n\t</item>\n";
    }
    outfile.close();
}

PapaXmasConveyorBeltRand *createConveyorBeltRand()
{
    PapaXmasConveyorBeltRand *Cb = new PapaXmasConveyorBeltRand;
    return Cb;
}