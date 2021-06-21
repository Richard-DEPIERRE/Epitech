/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-richard.habimana
** File description:
** Nibller
*/
#include <vector>
#include <string>
#include <math.h>
#include "SnakeBody.hpp"
#include "IGameModule.hpp"
#include "UtilityClasses.hpp"
#include "Fruit.hpp"


#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_

class SnakeBody;

enum Content {
    NIBBLER,
    WALL,
    APPLE,
    GROUND,
    TAIL,
    BODY
};

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Nibbler : public arcade::IGameModule {
    public:
        Nibbler();
        ~Nibbler();
        void update(Vector2i mouse, char key);
        void handleMouseEvent(void);
        void handleKeyEvent(char key);
        void initObjects(void);
        void move(int x, int y);
        void moveNibbler(int, Direction, SnakeBody);
        void changeDirection(char);
        object::Object returnObject(std::string filepath, Content content, float posx, float posy, Vector2i vec = Vector2i(0, 0), Vector2i size = Vector2i(0, 0), Vector2i scale = Vector2i(0, 0), int level = 0);
        void createObject(std::string filepath, Content content, float posx, float posy, Vector2i vec = Vector2i(0, 0), Vector2i size = Vector2i(0, 0), Vector2i scale = Vector2i(0, 0), int level = 0);
        std::vector<object::Object> getObjects() {return this->_objects;};
        void changeSpriteRect(Direction direction, int index, SnakeBody body);
        void changeHead(Direction direction, int index, int x, int y);
        void changeTail(Direction direction, int index, int x, int y);
        void changeBody(Direction direction, int index, int x, int y, SnakeBody body);
        bool checkwalls(Vector2i posHead, int diffX = 0, int diffY = 0);
        int checkfruits(Vector2i posHead, int diffX = 0, int diffY = 0);
        Settings getSetting(void) { return this->_settings; }
        void updatePlayer();
        void createNewPart(int index);
        void initSettings(void);

    protected:
    private:
        std::vector<std::string> _map;
        std::vector<object::Object> _objects;
        std::size_t _scene;
        std::size_t _clock;
        Direction direction = RIGHT;
        std::vector<SnakeBody> _snake;
        int indexHead = 0;
        Vector2i posHead;
        std::vector<Vector2i> walls;
        std::vector<Fruit> fruits;
        Settings _settings;
};

#endif /* !SNAKE_HPP_ */
