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
#include "Hospital.hpp"

Hospital::Hospital()
{
    this->doctors = nullptr;
    this->nurses = nullptr;
    this->sicks = nullptr;
}

Hospital::~Hospital()
{
}

void Hospital::addDoctor(KoalaDoctorList *new_doctor)
{
    if (this->doctors && this->doctors->getFromName(new_doctor->getContent()->getName()))
        return ;
    if (this->doctors == nullptr)
        this->doctors = new_doctor;
    else
        this->doctors->append(new_doctor);
    std::cout << "[HOSPITAL] Doctor " << new_doctor->getContent()->getName() << " just arrived!" << std::endl;
    new_doctor->getContent()->timeCheck();
}

void Hospital::addNurse(KoalaNurseList *new_nurse)
{
    if (this->nurses && this->nurses->getFromID(new_nurse->getContent()->getId()))
        return ;
    if (this->nurses == nullptr)
        this->nurses = new_nurse;
    else
        this->nurses->append(new_nurse);
    std::cout << "[HOSPITAL] Nurse " << new_nurse->getContent()->getId() << " just arrived!" << std::endl;
    new_nurse->getContent()->timeCheck();
}

void Hospital::addSick(SickKoalaList *new_sick)
{
    if (this->sicks && this->sicks->getFromName(new_sick->getContent()->getName()))
        return ;
    if (this->sicks == nullptr)
        this->sicks = new_sick;
    else
        this->sicks->append(new_sick);
    std::cout << "[HOSPITAL] Patient " << new_sick->getContent()->getName() << " just arrived!" << std::endl;
}

void Hospital::run()
{
    std::cout << "[HOSPITAL] Work starting with:" << std::endl;
    this->doctors->dump();
    this->nurses->dump();
    this->sicks->dump();
    std::cout << std::endl;
    KoalaDoctorList *list_doctor = this->doctors;
    KoalaNurseList *list_nurse = this->nurses;
    for (SickKoalaList *list_sick = this->sicks; list_sick; list_sick = list_sick->getNext()) {
        list_doctor->getContent()->diagnose(list_sick->getContent());
        std::string drug = list_nurse->getContent()->readReport(list_sick->getContent()->getName() + ".report");
        list_nurse->getContent()->giveDrug(drug, list_sick->getContent());
        list_nurse = (list_nurse->isEnd()) ? this->nurses : list_nurse->getNext();
        list_doctor = (list_doctor->isEnd()) ? this->doctors : list_doctor->getNext();
    }
    for(; this->nurses; this->nurses = this->nurses->removeFromID(this->nurses->getContent()->getId()))
        this->nurses->getContent()->timeCheck();
    for(; this->doctors; this->doctors = this->doctors->removeFromName(this->doctors->getContent()->getName()))
        this->doctors->getContent()->timeCheck();
    for(; this->sicks; this->sicks = this->sicks->removeFromName(this->sicks->getContent()->getName()));
}