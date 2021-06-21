/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** pacman
*/

#include "pacman.hpp"

Pacman::Pacman() : _settings("musicPath", "assetsPath")
{
    std::ifstream file;
    std::string content;

    file.open("assets/pacman/background.txt");
    if (!file) {
        std::cerr << "File is not open" << std::endl;
        return;
    }
    if (file.peek() == std::ifstream::traits_type::eof()) {
        std::cerr << "File is empty" << std::endl;
        return;
    }
    for (int lineNbr = 1; std::getline(file, content); lineNbr++)
        this->_map.push_back(content);
    this->initObjects();
    this->initSettings();
    this->_clock = 0;
    this->_side = 4;
    this->_sideTemp = 4;
}

void Pacman::initSettings(void)
{
    // TODO
    this->_settings.setScore(0);
}

void Pacman::createObject(Content content, std::size_t posx, std::size_t posy, Vector2i vec, Vector2i size, Vector2f scale, Vector2i mult, int level)
{
    object::Object obj;
    object::Sprite_t sprite;
    sprite._filePath = "assets/pacman/" + _contentName[content] + ".png";
    sprite._mult.setX(mult.getX());
    sprite._mult.setY(mult.getY());
    sprite._extra.set(0, 0);
    sprite._rectSize.setX(vec.getX());
    sprite._rectSize.setY(vec.getY());
    sprite._sizeSquare.setX(size.getX());
    sprite._sizeSquare.setY(size.getY());
    sprite._scale.setX(scale.getX());
    sprite._scale.setY(scale.getY());
    if (content == GHOST1) {
        obj.setColor(Vector3i(255, 0, 255));
        sprite._charNcurse = '1';
    }
    if (content == GHOST2) {
        obj.setColor(Vector3i(255, 0, 0));
        sprite._charNcurse = '2';
    }
    if (content == GHOST3) {
        obj.setColor(Vector3i(0, 255, 255));
        sprite._charNcurse = '3';
    }
    if (content == GHOST4) {
        obj.setColor(Vector3i(0, 0, 255));
        sprite._charNcurse = '4';
    }
    if (content == WALL) {
        sprite._charNcurse = '#';
        obj.setColor(Vector3i(255, 255, 255));
    }
    if (content == PACMAN) {
        sprite._charNcurse = 'P';
        obj.setColor(Vector3i(255, 255, 0));
    }
    if (content == GUM) {
        sprite._charNcurse = '-';
        obj.setColor(Vector3i(255, 255, 0));
    }
    if (content == PACGUM) {
        sprite._charNcurse = 'o';
        obj.setColor(Vector3i(255, 255, 255));
    }
    if (content == PORTAL) {
        sprite._charNcurse = '|';
        obj.setColor(Vector3i(0, 0, 0));
    }
    obj.setSprite(sprite);
    obj.setActive(true);
    obj.setPos(Vector2i(posx, posy));
    obj.setLevel(level);
    obj.setContent(content);
    this->_objects.push_back(obj);
}

void Pacman::initObjects(void)
{
    for (std::size_t y = 1; y < this->_map.size() - 1; y++) {
        for (std::size_t x = 1; x < this->_map[y].size() - 1; x++) {
            if (this->_map[y][x] == '#') {
                std::unordered_map<std::string, char> square;
                square["uleft"] = this->_map[y - 1][x - 1];
                square["left"] = this->_map[y][x - 1];
                square["dleft"] = this->_map[y + 1][x - 1];
                square["down"] = this->_map[y + 1][x];
                square["dright"] = this->_map[y + 1][x + 1];
                square["right"] = this->_map[y][x + 1];
                square["uright"] = this->_map[y - 1][x + 1];
                square["up"] = this->_map[y - 1][x];
                this->createObject(WALL, (x - 1), (y - 1), createWalls(square), Vector2i(8, 8), Vector2f(3, 3), Vector2i(3*8, 3*8));
            } else if (this->_map[y][x] == 'd')
                this->createObject(GUM, (x - 1), (y - 1), Vector2i(117, 18), Vector2i(8, 8), Vector2f(3, 3), Vector2i(3*8, 3*8));
            else if (this->_map[y][x] == 'O')
                this->createObject(PACGUM, (x - 1), (y - 1), Vector2i(135, 18), Vector2i(8, 8), Vector2f(3, 3), Vector2i(3*8, 3*8));
            else if (this->_map[y][x] == 'P')
                this->createObject(PACMAN, (x - 1), (y - 1), Vector2i(0, 0), Vector2i(24, 24), Vector2f(1, 1), Vector2i(3*8, 3*8), 1);
            else if (this->_map[y][x] == '1')
                this->createObject(GHOST1, (x - 1), (y - 1), Vector2i(0, 0), Vector2i(24, 24), Vector2f(1, 1), Vector2i(3*8, 3*8), 1);
            else if (this->_map[y][x] == '2')
                this->createObject(GHOST2, (x - 1), (y - 1), Vector2i(24, 0), Vector2i(24, 24), Vector2f(1, 1), Vector2i(3*8, 3*8), 1);
            else if (this->_map[y][x] == '3')
                this->createObject(GHOST3, (x - 1), (y - 1), Vector2i(48, 0), Vector2i(24, 24), Vector2f(1, 1), Vector2i(3*8, 3*8), 1);
            else if (this->_map[y][x] == '4')
                this->createObject(GHOST4, (x - 1), (y - 1), Vector2i(72, 0), Vector2i(24, 24), Vector2f(1, 1), Vector2i(3*8, 3*8), 1);
            else if (this->_map[y][x] >= '|')
                this->createObject(PORTAL, (x - 1), (y - 1), Vector2i(126, 18), Vector2i(8, 8), Vector2f(3, 3), Vector2i(3*8, 3*8));
        }
    }
}

void Pacman::updatePosGhost()
{
    if (this->_side == 0) {
        this->move(1, 0);
    } else if (this->_side == 2) {
        this->move(-1, 0);
    } else if (this->_side == 1) {
        this->move(0, -1);
    } else if (this->_side == 3) {
        this->move(0, 1);
    }
}

void Pacman::update(Vector2i mouse, char key)
{
    this->_clock++;
    this->handleKeyEvent(key);
    if (!checkpos(this->_sideTemp)) {
        this->_side = 4;
        this->_sideTemp = 4;
    } else
        setRect(this->_side);
    if (this->_clock == 24) {
        this->_clock = 0;
        if (checkpos(this->_sideTemp)) {
            this->_side = this->_sideTemp;
            setPos(this->_side);
        } else {
            this->_side = 4;
            this->_sideTemp = 4;
        }
        for (std::size_t i = 0; i < this->_objects.size(); i++)
            if (this->_objects[i].getContent() == PACMAN) {
                object::Sprite_t sprite = this->_objects[i].getSprite();
                sprite._extra.setX(0);
                sprite._extra.setY(0);
                this->_objects[i].setSprite(sprite);
            }
    }
    else
        this->updatePosGhost();
}

void Pacman::handleMouseEvent(void)
{
}

void Pacman::setRect(std::size_t side)
{
    object::Sprite_t sprite;
    for (std::size_t i = 0; i < this->_objects.size(); i++)
        if (this->_objects[i].getContent() == PACMAN)
            sprite = this->_objects[i].getSprite();
    if (side == 0)
        sprite._rectSize.set(0, 0);
    else if (side == 2)
        sprite._rectSize.set(48, 0);
    else if (side == 1)
        sprite._rectSize.set(24, 0);
    else if (side == 3)
        sprite._rectSize.set(72, 0);
    for (std::size_t i = 0; i < this->_objects.size(); i++)
        if (this->_objects[i].getContent() == PACMAN)
            this->_objects[i].setSprite(sprite);
}

void Pacman::setPos(std::size_t side)
{
    Vector2i pos;
    object::Sprite_t sprite;
    for (std::size_t i = 0; i < this->_objects.size(); i++)
        if (this->_objects[i].getContent() == PACMAN) {
            pos.set(this->_objects[i].getPos().getX(), this->_objects[i].getPos().getY());
            sprite = this->_objects[i].getSprite();
        }
    if (side == 0) {
        pos.addX(1);
        sprite._rectSize.set(0, 0);
    } else if (side == 2) {
        pos.addX(-1);
        sprite._rectSize.set(48, 0);
    } else if (side == 1) {
        pos.addY(-1);
        sprite._rectSize.set(24, 0);
    } else if (side == 3) {
        pos.addY(1);
        sprite._rectSize.set(72, 0);
    }
    for (std::size_t i = 0; i < this->_objects.size(); i++)
        if (this->_objects[i].getContent() == PACMAN) {
            this->_objects[i].setPos(pos);
            this->_objects[i].setSprite(sprite);
        }
}

void Pacman::updateScorePacmanEats(object::Object obj)
{
    if (obj.getContent() == GUM) {
        this->_settings.setScore(this->_settings.getScore() + 10);
        return;
    }
    if (obj.getContent() == PACGUM) {
        this->_settings.setScore(this->_settings.getScore() + 50);
        return;
    }
    if (obj.getContent() == GHOST1) {
        this->_settings.setScore(this->_settings.getScore() + 200);
        return;
    }
    if (obj.getContent() == GHOST2) {
        this->_settings.setScore(this->_settings.getScore() + 400);
        return;
    }
    if (obj.getContent() == GHOST3) {
        this->_settings.setScore(this->_settings.getScore() + 800);
        return;
    }
    if (obj.getContent() == GHOST4) {
        this->_settings.setScore(this->_settings.getScore() + 1600);
        return;
    }
}

bool Pacman::checkpos(std::size_t side)
{
    Vector2i pos;
    Vector2i posTemp;
    for (std::size_t i = 0; i < this->_objects.size(); i++)
        if (this->_objects[i].getContent() == PACMAN)
            pos.set(this->_objects[i].getPos().getX(), this->_objects[i].getPos().getY());
    posTemp.set(pos.getX(), pos.getY());
    if (side == 0)
        pos.addX(1);
    else if (side == 2)
        pos.addX(-1);
    else if (side == 1)
        pos.addY(-1);
    else if (side == 3)
        pos.addY(1);
    for (std::size_t i = 0; i < this->_objects.size(); i++)
        if (this->_objects[i].getLevel() != -1 && posTemp.getX() == this->_objects[i].getPos().getX() && posTemp.getY() == this->_objects[i].getPos().getY() && (this->_objects[i].getContent() == GUM || this->_objects[i].getContent() == PACGUM)) {
            this->_objects[i].setLevel(-1);
            this->updateScorePacmanEats(this->_objects[i]);
        }
    for (std::size_t i = 0; i < this->_objects.size(); i++) {
        if (pos.getX() == this->_objects[i].getPos().getX() && pos.getY() == this->_objects[i].getPos().getY() && (this->_objects[i].getContent() == WALL || this->_objects[i].getContent() == PORTAL)) {
            return false;
        }
    }
    return true;
}

void Pacman::move(int xpos, int ypos)
{
    for (std::size_t i = 0; i < this->_objects.size(); i++)
        if (this->_objects[i].getContent() == PACMAN) {
            object::Sprite_t sprite = this->_objects[i].getSprite();
            sprite._extra.addX(xpos);
            sprite._extra.addY(ypos);
            this->_objects[i].setSprite(sprite);
        }
}

void Pacman::handleKeyEvent(char key)
{
    if (this->_side == 4) {
        if (key == '>')
            this->_side = 0;
        else if (key == '<')
            this->_side = 2;
        else if (key == '^')
            this->_side = 1;
        else if (key == 'V')
            this->_side = 3;
    } else {
        if (key == '>')
            this->_sideTemp = 0;
        else if (key == '<')
            this->_sideTemp = 2;
        else if (key == '^')
            this->_sideTemp = 1;
        else if (key == 'V')
            this->_sideTemp = 3;
    }
}

Pacman::~Pacman()
{

}