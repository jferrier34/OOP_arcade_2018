/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** libncurses
*/

#ifndef LIBNCURSES_HPP_
    #define LIBNCURSES_HPP_

#include <ncurses.h>
#include "Ilib.hpp"

class libncurses : public Ilib
{
public:
	libncurses();
	~libncurses();
	void	destroy();
	void	refreshWindow();
	int	getchWindow();
	int	menuGame();
	void	initText();
	void	swapLibs();
	void	swapGames();
	void	printMap();
	void	setMap(std::vector<std::vector<char>>);
	std::string	getGameName();
	std::string	getLibName();
	void	setScore(int);
private:
	WINDOW	* _win;
	int	ch;
	std::vector<std::string>	_textLib;
	std::vector<std::string>	_textGame;
};

#endif /* !LIBNCURSES_HPP_ */

