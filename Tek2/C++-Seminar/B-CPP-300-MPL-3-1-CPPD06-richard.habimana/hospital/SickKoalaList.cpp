/*
** EPITECH PROJECT, 2021
** main.cpp
** File description:
** main
*/

#include <fstream>
#include <string>
#include <iostream>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include "SickKoalaList.hpp"

SickKoalaList::SickKoalaList(SickKoala *sick): sick(sick)
{
    next = nullptr;
}

SickKoalaList::~SickKoalaList()
{
}

bool SickKoalaList::isEnd()
{
    if (next == nullptr)
        return true;
    return false;
}

void SickKoalaList::append(SickKoalaList *patient)
{
    SickKoalaList *tmp = this;

    if (!tmp) {
        tmp = patient;
        tmp->next = nullptr;
        return;
    }
    for (; !tmp->isEnd(); tmp = tmp->next);
    tmp->next = patient;
    tmp->next->next = nullptr;
}

SickKoala *SickKoalaList::getFromName(std::string str)
{
    for (SickKoalaList *tmp = this; tmp; tmp = tmp->next)
        if (tmp->sick->getName() == str)
            return (tmp->sick);
    return (nullptr);
}

SickKoalaList *SickKoalaList::remove(SickKoalaList *new_node)
{
    if (this == new_node)
        return this->next;
    for (SickKoalaList *tmp = this; tmp; tmp = tmp->next)
        if (tmp->next == new_node) {
            tmp->next = tmp->next->next;
        }
    return (this);
}

SickKoalaList *SickKoalaList::removeFromName(std::string name)
{
    SickKoalaList *previous = NULL;
    for (SickKoalaList *current = this; current;previous = current, current = current->next)
        if (current && current->sick && current->sick->getName() == name) {
            if (previous) {
                previous->next = current->next;
                current->next = NULL;
                return this;
            } else {
                previous = current->next;
                current->next = NULL;
                return previous;
            }
        }
    return NULL;
}

SickKoala *SickKoalaList::getContent()
{
    return (this->sick);
}

SickKoalaList *SickKoalaList::getNext()
{
    return (this->next);
}

void SickKoalaList::dump()
{
    std::string null_str = "[nullptr]";

    std::cout << "Patients: ";
    for (SickKoalaList *tmp = this; tmp; tmp = tmp->next) {
        if (tmp->getContent())
            std::cout << tmp->getContent()->getName();
        else
            std::cout << "[nullptr]";
        if (!tmp->next)
            std::cout <<  ".\n";
        else
            std::cout <<  ", ";
    }
}