/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** libsfml
*/

#ifndef LIBSFML_HPP_
    #define LIBSFML_HPP_


#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Ilib.hpp"

typedef	enum	e_map
{
	HEAD,
	BODY,
	FOOD,
	MAP
}		t_map;

class libsfml : public Ilib
{
public:
	libsfml();
	~libsfml();
	void	destroy();
	void	refreshWindow();
	int	getchWindow();
	void	initText();
	int	menuGame();
	void	swapGames();
	void	swapLibs();
	void	printMap();
	void	setMap(std::vector<std::vector<char>>);
	std::string	getGameName();
	std::string	getLibName();
	void	setScore(int);
private:
	sf::RenderWindow	_win;
	sf::Font	_font;
	sf::Text	_textLib[2];
	sf::Text	_textGame[2];
};


#endif /* !LIBSFML_HPP_ */
