/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Igame
*/

#ifndef IGAME_HPP_
    #define IGAME_HPP_

# include <iostream>
# include <vector>
# include <map>
# include <algorithm>
# include <array>

class	Igame
{
protected:
	int     score;
	std::vector<std::vector<char>>	_map;
public:
	virtual	int				game() = 0;
	virtual	int				getScore() = 0;
	virtual	std::vector<std::vector<char>>	getMap() = 0;
	virtual	int	initMap(int, int) = 0;
	virtual	void	touchKey(int) = 0;
	virtual	int	getGameover() = 0;
};

typedef	Igame	*(*maker_game)();

#endif /* !IGAME_HPP_ */
