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
#include "KoalaDoctorList.hpp"

KoalaDoctorList::KoalaDoctorList(KoalaDoctor *doctor): doctor(doctor)
{
    next = nullptr;
}

KoalaDoctorList::~KoalaDoctorList()
{
}

bool KoalaDoctorList::isEnd()
{
    if (next == nullptr)
        return true;
    return false;
}

void KoalaDoctorList::append(KoalaDoctorList *new_node)
{
    KoalaDoctorList* tmp = this;
    if (new_node)
        new_node->next = nullptr;
    for (; tmp->next ; tmp = tmp->next);
    tmp->next = new_node;
}

KoalaDoctor *KoalaDoctorList::getFromName(std::string str)
{
    for (KoalaDoctorList *tmp = this; tmp; tmp = tmp->next)
        if (tmp->doctor->getName() == str)
            return (tmp->doctor);
    return (nullptr);
}

KoalaDoctorList *KoalaDoctorList::remove(KoalaDoctorList *new_node)
{
    if (this == new_node)
        return this->next;
    for (KoalaDoctorList *tmp = this; tmp; tmp = tmp->next)
        if (tmp->next == new_node) {
            tmp->next = tmp->next->next;
        }
    return (this);
}

KoalaDoctorList *KoalaDoctorList::removeFromName(std::string str)
{
    KoalaDoctorList *previous = NULL;
    for (KoalaDoctorList *current = this; current;previous = current, current = current->next)
        if (current && current->doctor && current->doctor->getName() == str) {
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

KoalaDoctor *KoalaDoctorList::getContent()
{
    return (this->doctor);
}

KoalaDoctorList *KoalaDoctorList::getNext()
{
    return (this->next);
}

void KoalaDoctorList::dump()
{
    std::string null_str = "[nullptr]";

    std::cout << "Doctors: ";
    for (KoalaDoctorList *tmp = this; tmp; tmp = tmp->next) {
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