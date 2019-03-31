/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** libsfml
*/

#include <unistd.h>
#include <sstream>
#include "libsfml.hpp"

libsfml::libsfml()
{
	this->libName.assign("./lib_arcade_sfml.so");
	this->gameName.assign("/games/Nibbler.so");
	this->width = 200;
	this->height = 200;
	_win.create(sf::VideoMode(1600, 800), "my window");
	initText();
}

libsfml::~libsfml()
{
}

void	libsfml::setScore(int val)
{
	this->_score = val;
}

void	libsfml::destroy()
{
	this->_win.close();
}

void	libsfml::initText()
{
	_font.loadFromFile("lib/Source/arial.ttf");
	_textLib[0].setString("./lib_arcade_ncurses.so");
	_textLib[0].setFont(_font);
	_textLib[0].setCharacterSize(32);
	_textLib[0].setPosition(sf::Vector2f(250, 200));

	_textLib[1].setString("./lib_arcade_sfml.so");
	_textLib[1].setFont(_font);
	_textLib[1].setCharacterSize(32);
	_textLib[1].setPosition(sf::Vector2f(250, 300));

	_textGame[0].setString("games/Nibbler.so");
	_textGame[0].setFont(_font);
	_textGame[0].setCharacterSize(32);
	_textGame[0].setPosition(sf::Vector2f(250, 600));

	_textGame[1].setString("games/Centiped.so");
	_textGame[1].setFont(_font);
	_textGame[1].setCharacterSize(32);
	_textGame[1].setPosition(sf::Vector2f(250, 700));
}

void	libsfml::swapLibs()
{
	sf::Text	text;

	text.setString(_textLib[0].getString());
	_textLib[0].setString(_textLib[1].getString());
	_textLib[1].setString(text.getString());
}

void	libsfml::swapGames()
{
	sf::Text	text;

	text.setString(_textGame[0].getString());
	_textGame[0].setString(_textGame[1].getString());
	_textGame[1].setString(text.getString());
}

std::string	to_string(int value)
{
    std::ostringstream	oss;
    oss << value;
    return oss.str();
}

int	libsfml::menuGame()
{
	int	ch;

	this->libName.assign(_textLib[0].getString());
	this->gameName.assign(_textGame[0].getString());
	while ((ch = getchWindow()) != ENTER &&
		ch != CHANGE) {
		if (ch == CHANGELIB) {
			swapLibs();
			this->libName.assign(_textLib[0].getString());
		}
		if (ch == CHANGEGAME) {
			swapGames();
			this->gameName.assign(_textGame[0].getString());
		}
		_win.clear(sf::Color(127, 127, 127));
		_win.draw(_textLib[0]);
		_win.draw(_textLib[1]);
		_win.draw(_textGame[0]);
		_win.draw(_textGame[1]);
		_win.display();
	}
	return 1;
}

void	libsfml::refreshWindow()
{
	this->_win.clear();
}

int	findKey(sf::Keyboard::Key key)
{
	std::map<sf::Keyboard::Key, int>	mapKey =
		{{sf::Keyboard::Up, MV_UP},
		 {sf::Keyboard::Down, MV_DOWN},
		 {sf::Keyboard::Left, MV_LEFT},
		 {sf::Keyboard::Right, MV_RIGHT},
		 {sf::Keyboard::M, MENU},
		 {sf::Keyboard::R, RESTART},
		 {sf::Keyboard::B, BREAK},
		 {sf::Keyboard::C, CHANGE},
		 {sf::Keyboard::L, CHANGELIB},
		 {sf::Keyboard::G, CHANGEGAME},
		 {sf::Keyboard::E, ENTER},
		{sf::Keyboard::Space, SHOOT}};
	auto    search = mapKey.find(key);
	return search->second;
}

void	libsfml::printMap()
{
        unsigned int i = 0;
        unsigned int j = 0;
	sf::Text	backSlash;
	sf::Texture	tmp;
	sf::Sprite	tmpS;
	sf::Text	text;
	unsigned int t;
	unsigned int g = i;

	_win.clear();
	backSlash.setString(std::string("\n"));
        while (i < _map.size())
        {
		t = j;
                while (j < _map[i].size()) {
			if (_map[i][j] + 0 == -1) {
				tmp.loadFromFile("lib/sprites/foodSnake.png");
				tmpS.setTexture(tmp);
				tmpS.setPosition(sf::Vector2f(t, g));
				_win.draw(tmpS);
			}
			else if (_map[i][j] + 0 == 0){
				tmp.loadFromFile("lib/sprites/mapSnake.png");
				tmpS.setTexture(tmp);
				tmpS.setPosition(sf::Vector2f(t, g));
				_win.draw(tmpS);
			}
			else if (_map[i][j] + 0 == 1){
				tmp.loadFromFile("lib/sprites/headSnake.png");
				tmpS.setTexture(tmp);
				tmpS.setPosition(sf::Vector2f(t, g));
				_win.draw(tmpS);
			}
			else if (_map[i][j] + 0 == 2) {
				tmp.loadFromFile("lib/sprites/bodySnake.png");
				tmpS.setTexture(tmp);
				tmpS.setPosition(sf::Vector2f(t, g));
				_win.draw(tmpS);
			}
			else if (_map[i][j] + 0 == 3) {
				tmp.loadFromFile("lib/sprites/wallCentiped.png");
				tmpS.setTexture(tmp);
				tmpS.setPosition(sf::Vector2f(t, g));
				_win.draw(tmpS);
			}
			else if (_map[i][j] + 0 == 4) {
				tmp.loadFromFile("lib/sprites/vesoCentiped.png");
				tmpS.setTexture(tmp);
				tmpS.setPosition(sf::Vector2f(t, g));
				_win.draw(tmpS);
			}
			else if (_map[i][j] + 0 == 5) {
				tmp.loadFromFile("lib/sprites/missil.png");
				tmpS.setTexture(tmp);
				tmpS.setPosition(sf::Vector2f(t, g));
				_win.draw(tmpS);
			}
			t = t + 32;
			j++;
		}
		backSlash.setPosition(t, i);
		g += 32;
		i++;
		j = 0;
		_win.draw(backSlash);
	}
	text.setString(to_string(_score));
	text.setPosition(sf::Vector2f(t, g));
	text.setFont(_font);
	text.setCharacterSize(32);
	_win.draw(text);
	_win.display();
}

int	libsfml::getchWindow()
{
	sf::Event	event;

	if (this->_win.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			this->_win.close();
		        return -2;
		}
		else if (event.type == sf::Event::KeyPressed)
			return findKey(event.key.code);
		else
			return -1;
	}
	return -1;
}

std::string	libsfml::getGameName()
{
	return this->gameName;
}

std::string	libsfml::getLibName()
{
	return this->libName;
}

void	libsfml::setMap(std::vector<std::vector<char>> map)
{
	this->_map = map;
}

extern "C"
{
	Ilib *make_circle()
	{
		return new libsfml();
	}
}