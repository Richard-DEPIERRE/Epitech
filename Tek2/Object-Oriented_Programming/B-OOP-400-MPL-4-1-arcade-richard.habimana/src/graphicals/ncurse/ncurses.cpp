/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-richard.habimana
** File description:
** ncurses
*/

#include "ncurses.hpp"

void rectangle(int y1, int x1, int y2, int x2)
{
    mvhline(y1, x1, 0, x2-x1);
    mvhline(y2, x1, 0, x2-x1);
    mvvline(y1, x1, 0, y2-y1);
    mvvline(y1, x2, 0, y2-y1);
    mvaddch(y1, x1, ACS_ULCORNER);
    mvaddch(y2, x1, ACS_LLCORNER);
    mvaddch(y1, x2, ACS_URCORNER);
    mvaddch(y2, x2, ACS_LRCORNER);
}

void delay_ms(int delay)
{
	usleep((useconds_t)delay * 100);
}

ncurses::ncurses()
{
    this->name = "";
}

void ncurses::open(void)
{
     // INIT Ncurses
    initscr(); // Start ncurses
    noecho();
    curs_set(0); // Cursor invisible
    start_color();
    use_default_colors();
    nodelay(stdscr, true);
    keypad(stdscr, true);

    cbreak();

    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);

    // COLOR
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_GREEN);
    init_pair(4, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(5, COLOR_BLUE, COLOR_BLUE);
    init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(7, COLOR_BLUE, COLOR_BLACK);
    init_pair(8, COLOR_MAGENTA, COLOR_MAGENTA);
    init_pair(9, -1, COLOR_BLACK);
    init_pair(10, COLOR_YELLOW, COLOR_BLACK);
    init_pair(11, COLOR_BLUE, COLOR_BLACK);
    init_pair(12, COLOR_GREEN, COLOR_BLACK);

    init_pair(20, COLOR_WHITE, COLOR_BLACK);
    init_pair(21, COLOR_YELLOW, COLOR_BLACK);
    init_pair(22, COLOR_GREEN, COLOR_BLACK);
    init_pair(23, COLOR_BLUE, COLOR_BLACK);
    init_pair(24, COLOR_RED, COLOR_BLACK);
    init_pair(25, COLOR_BLACK, -1);
    init_pair(26, COLOR_CYAN, COLOR_BLACK);
    init_pair(27, COLOR_MAGENTA, COLOR_BLACK);

    this->initLeaderboard();
    refresh();
}

void ncurses::initLeaderboard(void)
{
    for (std::size_t i = 0; i < _gameLibNames.size(); i++) {
        this->_leader[_gameLibNames.at(i)] = getTopPlayers(_gameLibNames.at(i));
    }
}

bool ncurses::forceExitPoint(void)
{
    return false;
}


void ncurses::writeName(void)
{
    int ch = getchar();
    if (ch == 13 && this->name.size() == 3) {
        this->scene = 1;
        clear();
        refresh();
    }
    if (ch == 127 && this->name.size() > 0) {
        this->name.erase(this->name.size() - 1, this->name.size());
    } else if (this->name.size() < 3) {
        if (((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))) {
            std::cout << ch << std::endl;
            if (ch >= 'a' && ch <= 'z') {
                ch -= 32;
            }
            this->name.push_back(ch);
        }
    }
}

void ncurses::nameSelector(void)
{
    WINDOW *win;

    wbkgd(stdscr, COLOR_PAIR(9));
    refresh();

    win = subwin(stdscr, 3, 30, (LINES / 2) - 2, (COLS / 2) - 15);
    wattron(win, COLOR_PAIR(4));
    box(win, ACS_VLINE, ACS_HLINE);
    wattron(win, COLOR_PAIR(10));
    mvwprintw(win, 1, 1, "Enter your name: %s", this->name.c_str());
    wattroff(win, COLOR_PAIR(10));
    wrefresh(win);
    this->writeName();
    wattroff(win, COLOR_PAIR(4));
}

bool ncurses::handleClick(std::vector<std::string> games, std::vector<std::string> graphs)
{
    int x = this->clickedPos.getX();
    int y = this->clickedPos.getY();

    if (x < 0 || y < 0)
        return false;

    /* HANDLE CLICK GAMES */
    for (std::size_t i = 0; i < games.size(); i++) {
        if (x >= 6 && x <= 7 + games.at(i).size() && y == ((i + 1) * 2) + 1 + (LINES / 2) - 1) {
            this->idxGame = i;
            return false;
        }
    }

    /* HANDLE CLICK GRAPHS */
    for (std::size_t i = 0; i < graphs.size(); i++) {
        if (x >= COLS - 28 && x <= COLS - 29 + graphs.at(i).size() && y == ((i + 1) * 2) + 1 + (LINES / 2) - 1) {
            this->idxGraph = i;
            return false;
        }
    }

    /* HANDLE CLICK PLAY */
    if (x >= (COLS / 2) - 11 && x <= (COLS / 2) + 14 && y >= LINES - 7 && y <= LINES - 3)
        return true;
    return false;
}

void ncurses::menu(std::vector<std::string> games, std::vector<std::string> graphs)
{
    WINDOW *winGames;
    WINDOW *winGraphs;
    WINDOW *scores;

    wbkgd(stdscr, COLOR_PAIR(9));

    if (this->handleClick(games, graphs))
        this->playGame = true;

    for (std::size_t i = 0; i < 3; i++) {
        char c = this->name[i];
        attron(COLOR_PAIR(i + 10));
        std::vector<std::string> asciiLetter = getAsciiLetter(c);
        for (std::size_t y = 0; y < asciiLetter.size(); y++)
            mvprintw((3 + y) + 3, 1 + (i * 10), "%s", asciiLetter.at(y).c_str());
        attroff(COLOR_PAIR(i + 10));
    }

    attron(COLOR_PAIR(2));
    for (int i = 0; i < arcadeNameMenu.size(); i++) {
        mvprintw(3 + i, (COLS / 2) - 17, "%s", arcadeNameMenu.at(i).c_str());
    }
    attroff(COLOR_PAIR(2));

    attron(COLOR_PAIR(7));
    for (int i = 0; i < arcadePlayMenu.size(); i++) {
        mvprintw(LINES - 7 + i, (COLS / 2) - 11, "%s", arcadePlayMenu.at(i).c_str());
    }
    attroff(COLOR_PAIR(7));

    winGames = subwin(stdscr, (4 + (games.size() * 2)), 30, (LINES / 2) - 1, 2);
    winGraphs = subwin(stdscr, (4 + (graphs.size() * 2)), 30, (LINES / 2) - 1, COLS - 32);
    scores = subwin(stdscr, 15, 30, 1, COLS - 32);


    wattron(winGames, COLOR_PAIR(4));
    box(winGames, ACS_VLINE, ACS_HLINE);
    wattroff(winGames, COLOR_PAIR(4));
    wattron(winGames, COLOR_PAIR(10));
    mvwprintw(winGames, 1, 12, "GAMES");
    for (std::size_t i = 0; i < games.size(); i++) {
        if (this->idxGame == i)
            mvwprintw(winGames, ((i + 1) * 2) + 1, 1, " o");
        mvwprintw(winGames, ((i + 1) * 2) + 1, 3, " %s", games.at(i).c_str());
    }
    wattroff(winGames, COLOR_PAIR(10));

    wattron(winGraphs, COLOR_PAIR(5));
    box(winGraphs, ACS_VLINE, ACS_HLINE);
    wattroff(winGraphs, COLOR_PAIR(5));
    wattron(winGraphs, COLOR_PAIR(11));
    mvwprintw(winGraphs, 1, 11, "GRAPHICS");
    for (std::size_t i = 0; i < graphs.size(); i++) {
        if (this->idxGraph == i)
            mvwprintw(winGraphs, ((i + 1) * 2) + 1, 1, " o");
        mvwprintw(winGraphs, ((i + 1) * 2) + 1, 3, " %s", graphs.at(i).c_str());
    }
    wattroff(winGraphs, COLOR_PAIR(11));

    wattron(scores, COLOR_PAIR(8));
    box(scores, ACS_VLINE, ACS_HLINE);
    wattroff(scores, COLOR_PAIR(8));
    wattron(scores, COLOR_PAIR(6));
    mvwprintw(scores, 1, 11, "SCORES");
    std::vector<std::tuple<std::string, int>> leaderGame = this->_leader[games.at(this->idxGame)];
    for (std::size_t i = 0; i < leaderGame.size(); i++) {
        mvwprintw(scores, ((i + 1) * 2) + 1, 2, "%s: %d", std::get<0>(leaderGame[i]).c_str(), std::get<1>(leaderGame[i]));
    }
    wattroff(scores, COLOR_PAIR(6));

    wrefresh(winGames);
    wrefresh(winGraphs);
    wrefresh(scores);
    attroff(COLOR_PAIR(9));
}

std::unordered_map<std::string, std::string> *ncurses::displayMainMenu(std::vector<std::string> games, std::vector<std::string> graphs)
{
    std::unordered_map<std::string, std::string> *strings = new std::unordered_map<std::string, std::string>;
    clear();
    (*strings)["play"] = (this->playGame) ? "true" : "false";
    if (this->playGame) {
        (*strings)["name"] = name;
        (*strings)["game"] = games.at(this->idxGame);
        (*strings)["graph"] = graphs.at(this->idxGraph);
        this->playGame = false;
    }
    if (this->scene == 0) {
        this->nameSelector();
    } else {
        this->menu(games, graphs);
        usleep(90000);
    }
    refresh();
    return strings;
}

void ncurses::close(void)
{
    clear();
    refresh();
    endwin();
}

Vector2i ncurses::getEventClick(void)
{
    Vector2i res(-1, -1);
    MEVENT event;

    if (this->ch == KEY_MOUSE) {
        assert(getmouse(&event) == OK);
        res.setX(event.x);
        res.setY(event.y);
    }
    this->clickedPos = res;
    return res;
}

char ncurses::getKeyboardEvent(void)
{
    char res = 0;
    this->ch = wgetch(stdscr);

    if (this->ch == 259)
        res = '^';
    if (this->ch == 258)
        res = 'V';
    if (this->ch == 261)
        res = '>';
    if (this->ch == 260)
        res = '<';

    if (res != 0) {
        return res;
    }
    return this->ch;
}

void ncurses::displayLayout(std::size_t size, arcade::IGameModule *game)
{
    mvprintw(LINES - 2, 0, "name: %s / score: %d", this->name.c_str(), game->getSetting().getScore());
}

int getColorIdx(int x, int y, int z)
{
    int colorIdx = 20;

    if (x == 255 && y == 255 && z == 255) {
        colorIdx = 20; // WHITE
    } else if (x == 0 && y == 0 && z == 0) {
        colorIdx = 25; // BLACK
    } else if (x == 255 && y == 255 && z == 0) {
        colorIdx = 21; // YELLOW
    } else if (x == 0 && y == 255 && z == 0) {
        colorIdx = 22; // GREEN
    } else if (x == 0 && y == 0 && z == 255) {
        colorIdx = 23; // BLUE
    } else if (x == 255 && y == 0 && z == 0) {
        colorIdx = 24; // RED
    } else if (x == 0 && y == 255 && z == 255) {
        colorIdx = 26; // CYAN
    } else if (x == 255 && y == 0 && z == 255) {
        colorIdx = 27; // MAGENTA
    }
    return colorIdx;
}

void ncurses::objectColorOn(Vector3i color)
{
    int x = color.getX();
    int y = color.getY();
    int z = color.getZ();

    attron(COLOR_PAIR(getColorIdx(x, y, z)));
}

void ncurses::objectColorOff(Vector3i color)
{
    int x = color.getX();
    int y = color.getY();
    int z = color.getZ();

    attroff(COLOR_PAIR(getColorIdx(x, y, z)));
}

void ncurses::display(arcade::IGameModule *game)
{
    clear();
    std::vector<object::Object> obj = game->getObjects();
    for (int a = 0; a < 2; a++)
        for (std::size_t i = 0; i < obj.size(); i++)
            if (obj[i].getLevel() == a) {
                objectColorOn(obj[i].getColor());
                mvprintw(obj[i].getPos().getY(), obj[i].getPos().getX(), "%c", obj[i].getSprite()._charNcurse);
                objectColorOff(obj[i].getColor());
            }
    this->displayLayout(obj.size(), game);
    refresh();
    delay_ms(300);
}

ncurses::~ncurses()
{
    clear();
    refresh();
    endwin();
}