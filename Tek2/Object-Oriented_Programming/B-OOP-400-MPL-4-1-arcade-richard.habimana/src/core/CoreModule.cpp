/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-richard.habimana
** File description:
** CoreModule
*/

#include <dirent.h>
#include <sys/types.h>
#include "CoreModule.hpp"

CoreModule::CoreModule(char *filepath)
{
    void *handle;
    std::string stringFilepath(filepath);

    if (stringFilepath.find("arcade_") == std::string::npos
    && stringFilepath.find(".so") == std::string::npos)
        errorDisplay(2, "Error name filepath");
    handle = dlopen(filepath, RTLD_LAZY);
    if (dlerror())
        errorDisplay(3, std::string("Error opening dynamic lib filepath : ").append(filepath));
    this->_graphLibrairies.push_back(this->exec->initGraph(handle));
    this->_graphLibName.push_back(this->parseFilename(stringFilepath));
    this->_handles.push_back(handle);
    this->updateLibrairies();
    this->exec = new Encapsulation();
    this->_menu = new std::unordered_map<std::string, std::string>;
    (*this->_menu)["play"] = "false";
}

std::string CoreModule::parseFilename(std::string filename)
{
    size_t pos = filename.find("arcade_") + 7;
    filename.erase(0, pos);
    pos = filename.find(".so");
    filename.erase(pos, filename.size() - 1);
    return filename;
}

bool CoreModule::isGraphLib(char *filename)
{
    for (auto it : this->_graphLibNames) {
        if (strcmp(filename, it.c_str()) == 0) {
            return true;
        }
    }
    return false;
}

bool CoreModule::isGameLib(char *filename)
{
    for (auto it : this->_gameLibNames) {
        if (strcmp(filename, it.c_str()) == 0) {
            return true;
        }
    }
    return false;
}

void CoreModule::updateLibrairies(void)
{
    void *handle;
    std::string path("./lib/");
    struct dirent *entry;
    DIR *dir = opendir(path.c_str());
    if (dir == NULL)
        return;

    while((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".gitignore") == 0
        || strcmp(entry->d_name, "..") == 0
        || strcmp(entry->d_name, ".") == 0
        || this->parseFilename(entry->d_name) == this->_graphLibName.at(0))
            continue;
        std::string finalPath("./lib/");
        finalPath.append(entry->d_name);
        handle = dlopen(finalPath.c_str(), RTLD_LAZY);
        if (dlerror())
            std::cerr << "Error opening dynamic lib filepath : " << finalPath << std::endl;
        else {
            // HANDLE GRAPH / GAME
            if (isGraphLib(entry->d_name)) {
                std::cout << entry->d_name << std::endl;
                this->_graphLibrairies.push_back(this->exec->initGraph(handle));
                this->_graphLibName.push_back(this->parseFilename(entry->d_name));
                this->_handles.push_back(handle);
            } else if (isGameLib(entry->d_name) == true) {
                this->_gameLibrairies.push_back(this->exec->initGame(handle));
                this->_gameLibName.push_back(this->parseFilename(entry->d_name));
                this->_handles.push_back(handle);
            } else {
                std::cerr << "Not loading " << entry->d_name << " file." << std::endl;
            }
        }
    }
    closedir(dir);
    this->_nbLibGame = this->_gameLibName.size();
    this->_nbLibGraph = this->_graphLibName.size();
}

void CoreModule::increaseGameIdx(void)
{
    if (this->_idxGame < this->_nbLibGame - 1) {
        this->_idxGame += 1;
    } else {
        this->_idxGame = 0;
    }
}

void CoreModule::decreaseGameIdx(void)
{
    if (this->_idxGame > 0) {
        this->_idxGame -= 1;
    } else {
        this->_idxGame = this->_nbLibGame - 1;
    }
}

void CoreModule::increaseGraphIdx(void)
{
    if (this->_idxGraph < this->_nbLibGraph - 1) {
        this->_idxGraph += 1;
    } else {
        this->_idxGraph = 0;
    }
}

void CoreModule::decreaseGraphIdx(void)
{
    if (this->_idxGraph > 0) {
        this->_idxGraph -= 1;
    } else {
        this->_idxGraph = this->_nbLibGraph - 1;
    }
}


void CoreModule::handlingChangingLib(char ch)
{
    if (ch == 'p') {
        std::cout << "Changing Graph lib" << std::endl;
        this->_graphLibrairies.at(this->_idxGraph)->close();
        this->increaseGraphIdx();
        this->_graphLibrairies.at(this->_idxGraph)->open();
    } else if (ch == 'o') {
        std::cout << "Changing Graph lib" << std::endl;
        this->_graphLibrairies.at(this->_idxGraph)->close();
        this->decreaseGraphIdx();
        this->_graphLibrairies.at(this->_idxGraph)->open();
    } else if (ch == 'm') {
        std::cout << "Changing Game lib" << std::endl;
        this->increaseGameIdx();
    } else if (ch == 'l') {
        std::cout << "Changing Game lib" << std::endl;
        this->decreaseGameIdx();
    } else if (ch == 'k') {
        (*this->_menu)["play"] = "false";
    }
}

void CoreModule::launchArcade(void)
{
    char ch = 0;
    this->_graphLibrairies.at(this->_idxGraph)->open();
    while (1) {
        bool closed = this->_graphLibrairies.at(this->_idxGraph)->forceExitPoint();
        ch = this->_graphLibrairies.at(this->_idxGraph)->getKeyboardEvent();
        if (ch == 27)
            closed = true;
        Vector2i pos = this->_graphLibrairies.at(this->_idxGraph)->getEventClick();
        this->handlingChangingLib(ch);
        if (closed) {
            this->_graphLibrairies.at(this->_idxGraph)->close();
            return;
        }
        if ((*this->_menu)["play"] == "false") {
            this->_menu =  this->_graphLibrairies.at(this->_idxGraph)->displayMainMenu(this->_gameLibName, this->_graphLibName);
            if ((*this->_menu)["play"] == "true") {
                for (std::size_t i = 0; i < this->_gameLibName.size(); i++)
                    if (this->_gameLibName[i] == (*this->_menu)["game"]) {
                        this->_idxGame = i;
                        break;
                    }
                for (std::size_t i = 0; i < this->_graphLibName.size(); i++) {
                    if (this->_graphLibName[i] == (*this->_menu)["graph"]) {
                        this->_graphLibrairies.at(this->_idxGraph)->close();
                        this->_idxGraph = i;
                        this->_graphLibrairies.at(this->_idxGraph)->open();
                        break;
                    }
                }
            }
        } else {
            this->_gameLibrairies.at(this->_idxGame)->update(pos, ch);
            this->_graphLibrairies.at(this->_idxGraph)->display(this->_gameLibrairies.at(this->_idxGame));
        }
    }
}

CoreModule::~CoreModule()
{
    for (auto &it : this->_handles)
        dlclose(it);
}
