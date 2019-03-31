/*
** EPITECH PROJECT, 2019
** snake.hpp
** File description:
** snake.hpp
*/

#ifndef SNAKE_HPP_
# define SNAKE_HPP_

# include <ctime>
# include <cstdio>
# include "../../Igame.hpp"

int	my_rand(int, int);

class Snake : public Igame
{
public:
	Snake();
	~Snake();
	int	game();
	int	getScore();
	std::vector<std::vector<char>>	getMap();
	int	initMap(int, int);
	void touchKey(int);
	void upgrade();
	void del_max();
	int	game_move();
	void placeApple();
	int	getGameover();
private:
	int	gameover;
	int	dir;
	int	x;
	int	y;
	int	w;
	int	h;
};

#endif

