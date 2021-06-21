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
#include "KoalaNurseList.hpp"

KoalaNurseList::KoalaNurseList(KoalaNurse *nurse): nurse(nurse)
{
    next = nullptr;
}

KoalaNurseList::~KoalaNurseList()
{
}

bool KoalaNurseList::isEnd()
{
    if (next == nullptr)
        return true;
    return false;
}

void KoalaNurseList::append(KoalaNurseList *new_node)
{
    KoalaNurseList* tmp = this;
    if (new_node)
        new_node->next = nullptr;
    for (; tmp->next ; tmp = tmp->next);
    tmp->next = new_node;
}

KoalaNurse *KoalaNurseList::getFromID(int id)
{
    for (KoalaNurseList *tmp = this; tmp; tmp = tmp->next)
        if (tmp->nurse->getId() == id)
            return (tmp->nurse);
    return (nullptr);
}

KoalaNurseList *KoalaNurseList::remove(KoalaNurseList *new_node)
{
    if (this == new_node)
        return this->next;
    for (KoalaNurseList *tmp = this; tmp; tmp = tmp->next)
        if (tmp->next == new_node) {
            tmp->next = tmp->next->next;
        }
    return (this);
}

KoalaNurseList *KoalaNurseList::removeFromID(int id)
{
    KoalaNurseList *previous = NULL;
    for (KoalaNurseList *current = this; current; previous = current, current = current->next)
        if (current && current->nurse && current->nurse->getId() == id) {
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

KoalaNurse *KoalaNurseList::getContent()
{
    return (this->nurse);
}

KoalaNurseList *KoalaNurseList::getNext()
{
    return (this->next);
}

void KoalaNurseList::dump()
{
    std::string null_str = "[nullptr]";

    std::cout << "Nurses: ";
    for (KoalaNurseList *tmp = this; tmp; tmp = tmp->next) {
        if (tmp->getContent())
            std::cout << tmp->getContent()->getId();
        else
            std::cout << "[nullptr]";
        if (!tmp->next)
            std::cout <<  ".\n";
        else
            std::cout <<  ", ";
    }
}