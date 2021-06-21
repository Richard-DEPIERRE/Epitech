/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-richard.habimana
** File description:
** Snake
*/

#include "Nibbler.hpp"

Nibbler::Nibbler(): _settings("musicPath", "folderPath")
{
    std::ifstream file;
    std::string content;

    file.open("assets/nibbler/background.txt");
    if (!file) {
        std::cerr << "File is not open" << std::endl;
        return;
    }
    if (file.peek() == std::ifstream::traits_type::eof()) {
        std::cerr << "File is empty" << std::endl;
        return;
    }
    for (int lineNbr = 0; std::getline(file, content); lineNbr++)
        this->_map.push_back(content);
    this->initObjects();
    this->_clock = 0;
    this->initSettings();
}

void Nibbler::initSettings(void)
{
    // TODO
    this->_settings.setScore(0);
}

void Nibbler::createObject(std::string filepath, Content content, float posx, float posy, Vector2i vec, Vector2i size, Vector2i scale, int level)
{
    object::Object obj;
    object::Sprite_t sprite;
    obj.setContent(content);
    sprite._filePath = filepath;
    sprite._rectSize.setX(vec.getX());
    sprite._rectSize.setY(vec.getY());
    sprite._sizeSquare.setX(size.getX());
    sprite._sizeSquare.setY(size.getY());
    sprite._scale.setX(scale.getX());
    sprite._scale.setY(scale.getY());
    obj.setSprite(sprite);
    obj.setActive(true);
    int x = round(posx);
    int y = round(posy);
    obj.setPos(Vector2i(x, y));
    obj.setLevel(level);
    this->_objects.push_back(obj);
}

object::Object Nibbler::returnObject(std::string filepath, Content content, float posx, float posy, Vector2i vec, Vector2i size, Vector2i scale, int level)
{
    object::Object obj;
    object::Sprite_t sprite;
    obj.setContent(content);
    sprite._filePath = filepath;
    sprite._rectSize.setX(vec.getX());
    sprite._rectSize.setY(vec.getY());
    sprite._sizeSquare.setX(size.getX());
    sprite._sizeSquare.setY(size.getY());
    sprite._scale.setX(scale.getX());
    sprite._scale.setY(scale.getY());
    obj.setSprite(sprite);
    obj.setActive(true);
    int x = round(posx);
    int y = round(posy);
    obj.setPos(Vector2i(x, y));
    obj.setLevel(level);
    return obj;
}

void Nibbler::initObjects(void)
{
    for (std::size_t y = 0; y < this->_map.size(); y++) {
        for (std::size_t x = 0; x < this->_map[y].size(); x++) {
            float xfloat = x;
            float yfloat = y;
            switch (this->_map[y][x])
            {
            case '1':
                this->createObject("assets/nibbler/snake.png", GROUND, xfloat * 8 * 6, yfloat * 8 * 6 , Vector2i(0, 0), Vector2i(8, 8), Vector2i(6, 6), 0);
                this->createObject("assets/nibbler/snake.png", WALL, xfloat * 8 * 6, yfloat * 8 * 6, Vector2i(96, 0), Vector2i(8, 8), Vector2i(6, 6), 1);
                this->walls.push_back(Vector2i(x, y));
                break;
            case '2':
                this->createObject("assets/nibbler/snake.png", GROUND, xfloat * 8 * 6, yfloat * 8 * 6 , Vector2i(0, 8), Vector2i(8, 8), Vector2i(6, 6), 0);
                this->createObject("assets/nibbler/snake.png", WALL, xfloat * 8 * 6, yfloat * 8 * 6, Vector2i(56, 16), Vector2i(8, 8), Vector2i(6, 6), 1);
                this->walls.push_back(Vector2i(x, y));
                break;
            case '3':
                this->createObject("assets/nibbler/snake.png", GROUND, xfloat * 8 * 6, yfloat * 8 * 6 , Vector2i(0, 8), Vector2i(8, 8), Vector2i(6, 6), 0);
                this->createObject("assets/nibbler/snake.png", WALL, xfloat * 8 * 6, yfloat * 8 * 6, Vector2i(72, 16), Vector2i(8, 8), Vector2i(6, 6), 1);
                this->walls.push_back(Vector2i(x, y));
                break;
            case '4':
                this->createObject("assets/nibbler/snake.png", GROUND, xfloat * 8 * 6, yfloat * 8 * 6 , Vector2i(0, 8), Vector2i(8, 8), Vector2i(6, 6), 0);
                this->createObject("assets/nibbler/snake.png", WALL, xfloat * 8 * 6, yfloat * 8 * 6, Vector2i(80, 16), Vector2i(8, 8), Vector2i(6, 6), 1);
                this->walls.push_back(Vector2i(x, y));
                break;
            case '5':
                this->createObject("assets/nibbler/snake.png", GROUND, xfloat * 8 * 6, yfloat * 8 * 6 , Vector2i(0, 8), Vector2i(8, 8), Vector2i(6, 6), 0);
                this->createObject("assets/nibbler/snake.png", WALL, xfloat * 8 * 6, yfloat * 8 * 6, Vector2i(64, 16), Vector2i(8, 8), Vector2i(6, 6), 1);
                this->walls.push_back(Vector2i(x, y));
                break;
            case '#':
                this->createObject("assets/nibbler/snake.png", GROUND, xfloat * 8 * 6, yfloat * 8 * 6 , Vector2i(0, 8), Vector2i(8, 8), Vector2i(6, 6), 0);
                break;
            case 'P':
                this->createObject("assets/nibbler/snake.png", GROUND, xfloat * 8 * 6, yfloat * 8 * 6 , Vector2i(0, 8), Vector2i(8, 8), Vector2i(6, 6), 0);
                this->createObject("assets/nibbler/snake.png", NIBBLER, xfloat * 8 * 6, yfloat * 8 * 6 , Vector2i(32, 24), Vector2i(8, 8), Vector2i(6, 6), 1);
                this->indexHead = this->_objects.size() - 1;
                posHead = Vector2i(x, y);
                break;
            case 'B':
                this->createObject("assets/nibbler/snake.png", GROUND, xfloat * 8 * 6, yfloat * 8 * 6 , Vector2i(0, 8), Vector2i(8, 8), Vector2i(6, 6), 0);
                this->createObject("assets/nibbler/snake.png", APPLE, xfloat * 8 * 6, yfloat * 8 * 6 , Vector2i(48, 0), Vector2i(8, 8), Vector2i(6, 6), 1);
                this->fruits.push_back(Fruit(this->_objects.size(), Vector2i(x, y)));
                break;
            case 'T':
                this->createObject("assets/nibbler/snake.png", GROUND, xfloat * 8 * 6, yfloat * 8 * 6 , Vector2i(0, 8), Vector2i(8, 8), Vector2i(6, 6), 0);
                this->createObject("assets/nibbler/snake.png", TAIL, xfloat * 8 * 6, yfloat * 8 * 6 , Vector2i(40, 24), Vector2i(8, 8), Vector2i(6, 6), 1);
                break;
            case 'C':
                this->createObject("assets/nibbler/snake.png", GROUND, xfloat * 8 * 6, yfloat * 8 * 6 , Vector2i(0, 8), Vector2i(8, 8), Vector2i(6, 6), 0);
                this->createObject("assets/nibbler/snake.png", BODY, xfloat * 8 * 6, yfloat * 8 * 6 , Vector2i(40, 24), Vector2i(8, 8), Vector2i(6, 6), 1);
            default:
                break;
            }
        }
    }
    int index = this->indexHead;
    SnakeBody part = SnakeBody(Vector2i(5, 15), RIGHT, index, NIBBLER);
    index-=2;
    SnakeBody part2 = SnakeBody(Vector2i(4, 15), RIGHT, index, BODY);
    index-=2;
    SnakeBody part3 = SnakeBody(Vector2i(3, 15), RIGHT, index, BODY);
    index-=2;
    SnakeBody part4 = SnakeBody(Vector2i(3, 15), RIGHT, index, BODY);
    index-=2;
    SnakeBody part5 = SnakeBody(Vector2i(2, 15), RIGHT, index, TAIL);
    index-=2;
    this->_snake.push_back(part);
    this->_snake.push_back(part2);
    this->_snake.push_back(part3);
    this->_snake.push_back(part4);
    this->_snake.push_back(part5);
}

void Nibbler::update(Vector2i pos, char key)
{
    this->_clock++;
    if (this->_clock == 40) {
        this->_clock = 0;
        changeDirection(key);
        updatePlayer();
    }
}

void Nibbler::createNewPart(int index)
{
    SnakeBody lastPart = this->_snake[this->_snake.size() - 1];
    int x = lastPart.getPos().getX();
    int y = lastPart.getPos().getY();
    Direction direction;
    if (lastPart.getDirection() == RIGHT) {
        x -= 1;
        direction = RIGHT;
    } else if (lastPart.getDirection() == LEFT) {
        x += 1;
        direction = LEFT;
    } else if (lastPart.getDirection() == UP) {
        y += 1;
        direction = UP;
    } else if (lastPart.getDirection() == DOWN) {
        y -= 1;
        direction = DOWN;
    }
    this->createObject("assets/nibbler/snake.png", BODY, x * 8 * 6, y * 8 * 6 , Vector2i(40, 24), Vector2i(8, 8), Vector2i(6, 6), 1);
    this->_snake.push_back(SnakeBody(Vector2i(x, y), direction, this->_objects.size() - 1, BODY));
}

void Nibbler::updatePlayer()
{
    for (std::size_t i = (this->_snake.size() - 1); i > 0; i--) {
        this->_snake[i].updateSnake(this->_snake[i-1]);
    }
    this->_snake[0].updateSnake(this->direction);
    for (std::size_t i = 0; i < this->_snake.size(); i++) {
        int index = this->_snake[i].getIndex();
        moveNibbler(index, this->_snake[i].getDirection(), this->_snake[i]);
        if (i == 0)
            changeSpriteRect(this->_snake[i].getDirection(), index, this->_snake[i]);
        else 
            changeSpriteRect(this->_snake[i].getDirection(), index, this->_snake[i-1]);
        index-=2;
    }
    bool quit = checkwalls(this->_snake[0].getPos());
    int bonus = checkfruits(this->_snake[0].getPos());
    if (quit == true)
        exit(84);
    if (bonus != 0) {
        createNewPart(bonus);
    }
   
}

void Nibbler::changeDirection(char key)
{
    Vector2i playerPos = this->_snake[0].getPos();
    switch (key)
    {
    case 81:
        if (this->direction != UP && !(checkwalls(playerPos, 0, 1)))
            this->direction = DOWN;
        break;
    case 82:
        if (this->direction != DOWN && !(checkwalls(playerPos, 0, -1)))
            this->direction = UP;
        break;
    case 80:
        if (this->direction != RIGHT && !(checkwalls(playerPos, -1, 0)))
            this->direction = LEFT;
        break;
    case 79:
        if (this->direction != LEFT && !(checkwalls(playerPos, 1, 0)))
            this->direction = RIGHT;
        break;
    default:
        break;
    }
}

void Nibbler::changeHead(Direction direction, int index, int x, int y)
{
    switch (direction) {
        case DOWN:
            this->_objects.at(index) = returnObject("assets/nibbler/snake.png", NIBBLER, x * 8 * 6, y * 8 * 6, Vector2i(24, 24), Vector2i(8, 8), Vector2i(6, 6), 1);
            break;
        case UP:
            this->_objects.at(index) = returnObject("assets/nibbler/snake.png", NIBBLER, x * 8 * 6, y * 8 * 6, Vector2i(8, 24), Vector2i(8, 8), Vector2i(6, 6), 1);
            break;
        case RIGHT:
            this->_objects.at(index) = returnObject("assets/nibbler/snake.png", NIBBLER, x * 8 * 6, y * 8 * 6, Vector2i(32, 24), Vector2i(8, 8), Vector2i(6, 6), 1);
            break;
        case LEFT:
            this->_objects.at(index) = returnObject("assets/nibbler/snake.png", NIBBLER, x * 8 * 6, y * 8 * 6, Vector2i(16, 24), Vector2i(8, 8), Vector2i(6, 6), 1);
            break;
        default:
            break;
    }
}

bool Nibbler::checkwalls(Vector2i posHead, int diffX, int diffY)
{
    for (int i = 0; i < walls.size(); i++) {
        if ((posHead.getX() + diffX) == walls[i].getX() && (posHead.getY() + diffY) == walls[i].getY())
            return true;
    }
    return false;
}

int Nibbler::checkfruits(Vector2i posHead, int diffX, int diffY)
{
    for (int i = 0; i < fruits.size(); i++) {
        if ((posHead.getX() + diffX) == fruits[i]._pos.getX() && (posHead.getY() + diffY) == fruits[i]._pos.getY())
            return fruits[i]._index;
    }
    return 0;
}


int getX(float scale, int pos, int size)
{
    int trueSize = size*scale;
    return (pos / trueSize);
}

void Nibbler::changeSpriteRect(Direction direction, int index, SnakeBody body)
{
    Vector2i scale = this->_objects[index].getSprite()._scale;
    Vector2i size = this->_objects[index].getSprite()._sizeSquare;
    Vector2i pos = this->_objects[index].getPos();
    int x = getX(scale.getX(), pos.getX(), size.getX());
    int y = getX(scale.getY(), pos.getY(), size.getY());

    switch (this->_objects[index].getContent()) {
        case NIBBLER:
            changeHead(direction, index, x, y);
            break;
        default:
            break;
    }

}

void Nibbler::moveNibbler(int index, Direction directionPart, SnakeBody body)
{
    Vector2i scale = this->_objects[index].getSprite()._scale;
    Vector2i size = this->_objects[index].getSprite()._sizeSquare;
    Vector2i pos = this->_objects[index].getPos();
    Vector2i newPos;
    switch (directionPart) {
        case UP:
            newPos.setX(pos.getX());
            newPos.setY(pos.getY() - size.getY() * scale.getY());
            this->_objects[index].setPos(newPos);
            break;

        case DOWN:
            newPos.setX(pos.getX());
            newPos.setY(pos.getY() + size.getY() * scale.getY());
            this->_objects[index].setPos(newPos);
            break;

        case LEFT:
            newPos.setX(pos.getX() - size.getX() * scale.getX());
            newPos.setY(pos.getY());
            this->_objects[index].setPos(newPos);
            break;

        case RIGHT:
            newPos.setX(pos.getX() + size.getX() * scale.getX());
            newPos.setY(pos.getY());
            this->_objects[index].setPos(newPos);
            break;
        default:
            break;
    }
}

void Nibbler::handleMouseEvent(void)
{

}

void Nibbler::handleKeyEvent(char key)
{

}
        

void Nibbler::move(int x, int y)
{

}

Nibbler::~Nibbler()
{
}