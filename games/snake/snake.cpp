/*
** EPITECH PROJECT, 2019
** snake.cpp
** File description:
** snake.cpp
*/

#include "snake.hpp"

Snake::Snake()
{
}

Snake::~Snake()
{
}

void	Snake::placeApple()
{
	int	x = my_rand(0, w);
	int	y = my_rand(0, h);

	while (_map[y][x] != 0)
	{
		x = my_rand(0, w);
		y = my_rand(0, h);
	}
	_map[y][x] = -1;
}

void	printMap(std::vector<std::vector<char>> map)
{
        unsigned int i = 0;
        unsigned int j = 0;
	
        while (i < map.size())
        {
                while (j < map[i].size())
                        std::cout << map[i][j++] + 0;
                i++;
                j = 0;
                std::cout << std::endl;
        }
}

void	Snake::del_max()
{
	int	i = -1;
	int	j = -1;
	int	max = -1;
	int	maxx;
	int	maxy;

	while (++i < this->h + 1)
	{
		j = -1;
		while (++j < this->w + 1)
		{
			if (this->_map[i][j] > max)
			{
				max = this->_map[i][j];
				maxx = j;
				maxy = i;
	      }
		}
	}
	this->_map[maxy][maxx] = 0;
}

void	Snake::upgrade()
{
	int	i = -1;
	int	j = -1;

	while (++i < this->h + 1)
	{
		j = -1;
		while (++j < this->w + 1)
		{
			if (this->_map[i][j] > 0)
				this->_map[i][j]++;
		}
	}
}


std::vector<std::vector<char>>	Snake::getMap()
{
	std::vector<std::vector<char>>	ret(_map);
	int	i = -1;
	int	j = -1;

	while (++i < this->h + 1)
	{
		j = -1;
		while (++j < this->w + 1)
		{
			if (this->_map[i][j] > 1)
				ret[i][j] = 2;
		}
	}
	return (ret);
}

int 	Snake::initMap(int x, int y)
{
	if (x < 10 || y < 10)
		x = y = 10;
	this->w = x - 1;
	this->h = y - 1;
	this->dir = 3;
	this->score = 0;
	this->gameover = 0;
	this->_map.resize(y, std::vector<char>(x, 0));
	this->_map[0][0] = 5;
	this->_map[0][1] = 4;
	this->_map[0][2] = 3;
	this->_map[0][3] = 2;
	this->_map[0][4] = 1;
	this->x = 4;
	this->y = 0;
	this->_map[my_rand(1, h)][my_rand(1, w)] = -1;
	return (1);
}

void	Snake::touchKey(int key)
{
	if (key == 0)
		this->dir = 4;
	if (key == 1)
		this->dir = 2;
	if (key == 2)
		this->dir = 1;
	if (key == 3)
		this->dir = 3;
	if (key == 5)
		initMap(w + 1, y + 1);
}

int	Snake::game_move()
{
	int	xp;
	int	yp;

	xp = this->x;
	yp = this->y;
	if (this->dir == 1) xp--;
	if (this->dir == 2) yp++;
	if (this->dir == 3) xp++;
	if (this->dir == 4) yp--;
	if (xp > this->w) xp = 0;
	if (xp < 0) xp = w;
	if (yp > this->h) yp = 0;
	if (yp < 0) yp = h;
	if (this->_map[yp][xp] > 0)
	{
		this->gameover = 1;
		return (0);
	}
	upgrade();
	if (this->_map[yp][xp] != -1)
		del_max();
	else
	{
		placeApple();
		this->score += 1;
	}
	this->_map[yp][xp] = 1;
	this->x = xp;
	this->y = yp;
	return (1);
}

int	Snake::game()
{
	game_move();
	return (1);
}

int	Snake::getGameover()
{
	return this->gameover;
}

int	Snake::getScore()
{
	return (this->score);
}

extern "C"
{
	Igame *make_game()
	{
		return new Snake();
	}
}
