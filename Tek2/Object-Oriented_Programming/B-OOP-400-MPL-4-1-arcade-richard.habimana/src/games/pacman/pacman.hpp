/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** pacman
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include <vector>
#include <string>
#include "IGameModule.hpp"
#include "UtilityClasses.hpp"

enum Content {
    PACMAN,
    WALL,
    GUM,
    PACGUM,
    PORTAL,
    GHOST1,
    GHOST2,
    GHOST3,
    GHOST4,
};

static std::vector<std::string> _contentName =
{
    "pacman", "wall", "wall", "wall", "wall",
       "ghost", "ghost", "ghost", "ghost"
};


class Pacman : public arcade::IGameModule {
    public:
        Pacman();
        ~Pacman();
        void update(Vector2i mouse, char key);
        void handleMouseEvent(void);
        void handleKeyEvent(char key);
        void initObjects(void);
        void move(int x, int y);
        void createObject(Content content, std::size_t posx, std::size_t posy, Vector2i vec = Vector2i(0, 0), Vector2i size = Vector2i(0, 0), Vector2f scale = Vector2f(0, 0), Vector2i mult = Vector2i(0, 0), int level = 0);
        std::vector<object::Object> getObjects() {return this->_objects;};
        bool checkpos(std::size_t side);
        void setPos(std::size_t side);
        void setRect(std::size_t side);
        Settings getSetting(void) { return this->_settings; }
        void updatePosGhost();
        void initSettings(void);
        void updateScorePacmanEats(object::Object obj);
    private:
        std::vector<std::string> _map;
        std::vector<object::Object> _objects;
        std::size_t _scene;
        std::size_t _clock;
        std::size_t _side;
        std::size_t _sideTemp;
        Settings _settings;


};

#endif /* !PACMAN_HPP_ */
