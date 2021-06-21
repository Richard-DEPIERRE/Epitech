/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD16-richard.habimana
** File description:
** DomesticKoala
*/

#include "DomesticKoala.hpp"

DomesticKoala::DomesticKoala(KoalaAction & action)
{
    _vectors = new std::vector<methodPointer_t>();
    _command = new std::vector<char>();
    _action = action;
}

DomesticKoala::~DomesticKoala()
{
    _vectors->clear();
    _command->clear();
    delete _vectors;
    delete _command;
}

DomesticKoala::DomesticKoala(const DomesticKoala &Koala)
{
    _vectors = new std::vector<methodPointer_t>(*(Koala._vectors));
    _command = new std::vector<char>(*(Koala._command));
    _action = Koala._action;

}

DomesticKoala &DomesticKoala::operator=(const DomesticKoala&Koala)
{
    _vectors->clear();
    _command->clear();
    delete _vectors;
    delete _command;
    _vectors = new std::vector<methodPointer_t>(*(Koala._vectors));
    _command = new std::vector<char>(*(Koala._command));
    _action = Koala._action;
    return (*this);
}

void DomesticKoala::learnAction(unsigned char command , methodPointer_t action)
{
    _vectors->push_back(action);
    _command->push_back(command);
}

void DomesticKoala::unlearnAction(unsigned char command)
{
    std::size_t i = 0;
    for (; i < _vectors->size(); i++)
        if ((*_command)[i] == command)
            break;
    if (i == _vectors->size())
        return;
    _vectors->erase(_vectors->begin()+i);
    _command->erase(_command->begin()+i);
}

void DomesticKoala::doAction(unsigned char command, const std::string &param)
{
    std::size_t i = 0;
    for (; i < _vectors->size(); i++)
        if ((*_command)[i] == command)
            break;
    if (i == _vectors->size())
        return;
    (_action.*(*_vectors)[i])(param);
}

void DomesticKoala::setKoalaAction(KoalaAction &newKoala)
{
    _action = newKoala;
}