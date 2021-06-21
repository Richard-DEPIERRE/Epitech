/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush2-richard.habimana
** File description:
** PapaXmasTable Rand
*/

#include "PapaXmasTableRand.hpp"

PapaXmasTableRand::PapaXmasTableRand()
{
    _objects._objects = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    _objects._names = {"", "", "", "", "", "", "", "", "", "", ""};
}

PapaXmasTableRand::~PapaXmasTableRand()
{
}

Object *PapaXmasTableRand::Take(int i)
{
    if (_objects._objects[i] == nullptr) {
        std::cerr << "No Objects found!" << std::endl;
        return nullptr;
    }
    if (_objects._names[i] == "Box" || _objects._names[i] == "GiftPaper" || _objects._names[i] == "FullBox" || _objects._names[i] == "FullGift")
        std::cout << "whistles while working" << std::endl;
    Object *res = _objects._objects[i];
    if (_objects._names[i] != "Box" && _objects._names[i] != "GiftPaper" && _objects._names[i] != "FullBox" && _objects._names[i] != "FullGift")
        std::cout << res->getTitle() << std::endl;
    _objects._objects[i] = nullptr;
    _objects._names[i] = "";
    return (res);
}

Object *PapaXmasTableRand::GetObject(int i)
{
    if (_objects._objects[i] == nullptr) {
        std::cerr << "No Objects found!" << std::endl;
        return nullptr;
    }
    return (_objects._objects[i]);
}

bool PapaXmasTableRand::Put(Object *object)
{
    if (object == nullptr) {
        std::cerr << "No Objects given!" << std::endl;
        return false;
    }
    for (int i = 0; i < 10; i++) {
        if (_objects._objects[i] == nullptr) {
            Toy *toy = dynamic_cast<Toy *>(object);
            if (toy)
                _objects._names[i] = "Toy";
            else {
                Box *box = dynamic_cast<Box *>(object);
                if (box)
                    _objects._names[i] = "Box";
                else
                    _objects._names[i] = "GiftPaper";
            }
            _objects._objects[i] = object;
            return true;
        }
    }
    std::cerr << "No more space on table!" << std::endl;
    return false;
}

std::array<std::string, 11> PapaXmasTableRand::look() const
{
    return _objects._names;
}

void PapaXmasTableRand::MakeNull(int i)
{
    _objects._objects[i] = nullptr;
    _objects._names[i] = "";
}

void PapaXmasTableRand::FullBox(int i)
{
    _objects._names[i] = "FullBox";
}

void PapaXmasTableRand::FullGift(int i)
{
    _objects._names[i] = "FullGift";
}

void PapaXmasTableRand::GetTitles()
{
    for (int i = 0; i < 10; i++) {
        if (_objects._objects[i])
            std::cout << _objects._objects[i]->getType() << std::endl;
    }
}

void PapaXmasTableRand::WrapMe(int wrapping, int wrapped)
{
    Box *box = (Box *)(_objects._objects[wrapping]);
    box->wrapMeThat(_objects._objects[wrapped]);
}

std::string PapaXmasTableRand::GetTitle(int i)
{
    return _objects._objects[i]->getTitle();
}

PapaXmasTableRand *createTableRand()
{
    PapaXmasTableRand *table = new PapaXmasTableRand();
    for (int i = 0; i < 10; i++) {
        switch ((std::rand()/((RAND_MAX + 1u) / 4)))
        {
        case PONY:
            table->Put(new LittlePony("pony"));
            break;
        case TEDDY:
            table->Put(new Teddy("bear"));
            break;
        case BOX:
            table->Put(new Box);
            break;
        case GIFTPAPER:
            table->Put(new GiftPaper);
            break;
        default:
            break;
        }
    }
    // table->GetTitles();
    return table;
}