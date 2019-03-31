/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Ilib
*/

#ifndef ILIB_HPP_
# define ILIB_HPP_

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <array>

typedef	enum	e_move {
	MV_UP,
	MV_DOWN,
	MV_LEFT,
	MV_RIGHT,
	MENU,
	RESTART,
	BREAK,
	CHANGE,
	CHANGELIB,
	CHANGEGAME,
	ENTER,
	SHOOT
}		t_move;

class	Ilib
{
protected:
	int width;
	int height;
	std::vector<std::vector<char>>	_map;
	std::string	libName;
	std::string	gameName;
	int	_score;
public:
	virtual	void	destroy() = 0;
	virtual void	refreshWindow() = 0;
	virtual int	getchWindow() = 0;
	virtual	int	menuGame() = 0;
	virtual	void	printMap() = 0;
	virtual	void	setMap(std::vector<std::vector<char>>) = 0;
	virtual std::string	getGameName() = 0;
	virtual std::string	getLibName() = 0;
	virtual	void	setScore(int) = 0;
};

typedef	Ilib	*(*maker_circle)();

#endif /* !ILIB_HPP_ */
