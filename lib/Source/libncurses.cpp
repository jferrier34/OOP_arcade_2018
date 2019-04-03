/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** libncurses
*/

#include "libncurses.hpp"

libncurses::libncurses()
{
	this->libName.assign("./lib_arcade_ncurses.so");
	this->gameName.assign("games/lib_arcade_nibbler.so");
	this->_win = NULL;
	this->width = 60;
	this->height = 60;
	curs_set(0);
	initscr();
	cbreak();
	noecho();
	timeout(1);
	keypad(stdscr, TRUE);
	initText();
}

libncurses::~libncurses()
{
}

void	libncurses::destroy()
{
	clear();
	endwin();
}

void	libncurses::initText()
{
	_textLib.push_back("./lib_arcade_ncurses.so");
	_textLib.push_back("./lib_arcade_sfml.so");
	_textGame.push_back("games/lib_arcade_nibbler.so");
	_textGame.push_back("games/lib_arcade_centipede.so");
}

void	libncurses::swapLibs()
{
        std::string	tmp;
	
	tmp.assign(_textLib.front());
	_textLib.front().assign(_textLib.back());
	_textLib.back().assign(tmp);
}

void	libncurses::swapGames()
{
        std::string	tmp;
	
	tmp.assign(_textGame.front());
	_textGame.front().assign(_textGame.back());
	_textGame.back().assign(tmp);
}

void	libncurses::setScore(int score)
{
	this->_score = score;
}

int	libncurses::menuGame()
{
	int	ch;

	this->libName.assign(_textLib[0]);
	this->gameName.assign(_textGame[0]);
	clear();
	printw("%s\n", (_textLib).front().c_str());
	printw("%s\n", (_textLib).back().c_str());
	printw("%s\n", (_textGame).front().c_str());
	printw("%s\n", (_textGame).back().c_str());
	refresh();
	while ((ch = getchWindow()) != ENTER &&
		ch != CHANGE) {
		if (ch == CHANGELIB) {
			swapLibs();
			this->libName.assign(_textLib[0]);
		}
		if (ch == CHANGEGAME) {
			swapGames();
			this->gameName.assign(_textGame[0]);
		}
		clear();
		printw("%s\n", (_textLib).front().c_str());
		printw("%s\n", (_textLib).back().c_str());
		printw("%s\n", (_textGame).front().c_str());
		printw("%s\n", (_textGame).back().c_str());
		refresh();
	}
	return 1;
}

int	findKey(int key)
{
	std::map<int, int>	mapKey =
		{{KEY_UP, MV_UP},
		 {KEY_DOWN, MV_DOWN},
		 {KEY_LEFT, MV_LEFT},
		 {KEY_RIGHT, MV_RIGHT},
		 {109, MENU},
		 {114, RESTART},
		 {98, BREAK},
		 {99, CHANGE},
		 {108, CHANGELIB},
		 {103, CHANGEGAME},
		 {101, ENTER},
		 {32, SHOOT}};
	auto    search = mapKey.find(key);
	return search->second;
}

int	libncurses::getchWindow()
{
	int key = getch();

	if (key)
		return findKey(key);
	return -1;
}

void	printThing(int val)
{
	std::map<int, char>	key;

	key =  {
		{-1, '*'},
		{0, ' '},
		{1, 'W'},
		{2, 'O'},
		{4, 'M'},
		{5, '|'},
		{3, 'N'}
	};
	auto	search = key.find(val);
	printw("%c", search->second);
}

void	libncurses::printMap()
{
        unsigned int i = 0;
        unsigned int j = 0;

	erase();
        while (i < _map.size())
        {
                while (j < _map[i].size())
			printThing(_map[i][j++]);
                i++;
                j = 0;
		printw("\n");
        }
	printw("%d\n", _score);
}

void	libncurses::refreshWindow()
{
	refresh();
}

std::string	libncurses::getGameName()
{
	return this->gameName;
}

std::string	libncurses::getLibName()
{
	return this->libName;
}

void	libncurses::setMap(std::vector<std::vector<char>> map)
{
	this->_map = map;
}

extern "C"
{
	Ilib *make_circle()
	{
		return new libncurses();
	}
}