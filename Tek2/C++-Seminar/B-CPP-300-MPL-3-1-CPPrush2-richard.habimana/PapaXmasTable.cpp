/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush2-richard.habimana
** File description:
** PapaXmasTable
*/

#include "PapaXmasTable.hpp"

PapaXmasTable::PapaXmasTable()
{
    _objects._objects = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    _objects._names = {"", "", "", "", "", "", "", "", "", "", ""};
}

PapaXmasTable::~PapaXmasTable()
{
}

Object *PapaXmasTable::Take(int i)
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

Object *PapaXmasTable::GetObject(int i)
{
    if (_objects._objects[i] == nullptr) {
        std::cerr << "No Objects found!" << std::endl;
        return nullptr;
    }
    return (_objects._objects[i]);
}

bool PapaXmasTable::Put(Object *object)
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

std::array<std::string, 11> PapaXmasTable::look() const
{
    return _objects._names;
}

void PapaXmasTable::MakeNull(int i)
{
    _objects._objects[i] = nullptr;
    _objects._names[i] = "";
}

void PapaXmasTable::FullBox(int i)
{
    _objects._names[i] = "FullBox";
}

void PapaXmasTable::FullGift(int i)
{
    _objects._names[i] = "FullGift";
}

void PapaXmasTable::GetTitles()
{
    for (int i = 0; i < 10; i++) {
        if (_objects._objects[i])
            std::cout << _objects._objects[i]->getType() << std::endl;
    }
}

void PapaXmasTable::WrapMe(int wrapping, int wrapped)
{
    Box *box = (Box *)(_objects._objects[wrapping]);
    box->wrapMeThat(_objects._objects[wrapped]);
}

std::string PapaXmasTable::GetTitle(int i)
{
    return _objects._objects[i]->getTitle();
}

PapaXmasTable *createTable()
{
    PapaXmasTable *table = new PapaXmasTable();
    table->Put(new LittlePony("pony"));
    table->Put(new Teddy("bear"));
    table->Put(new Box);
    table->Put(new Box);
    table->Put(new GiftPaper);
    table->Put(new GiftPaper);
    table->Put(new GiftPaper);
    table->Put(new GiftPaper);
    table->Put(new GiftPaper);
    table->Put(new GiftPaper);
    return table;
}