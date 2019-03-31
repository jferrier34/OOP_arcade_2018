//
// EPITECH PROJECT, 2018
// Arcade Game
// File description:
// shoot.cpp
//

#include "Include/shoot.hpp"

Shoot::Shoot()
{
	X = -1;
	Y = -1;
	selfDestruct = false;
	hitSomthing = false;
	shoted = false;
}

Shoot::~Shoot()
{
}

bool Shoot::isSelfDestruct()
{
	return selfDestruct;
}

bool Shoot::isHitSomthing()
{
	return hitSomthing;
}

bool Shoot::isShoted()
{
	return shoted;
}

std::vector<std::vector<char>> Shoot::reset(std::vector<std::vector<char>> map)
{
	map = unDraw(map);
	shoted = false;
	hitSomthing = false;
	selfDestruct = false;
	X = -1;
	Y = -1;
	return map;
}

void Shoot::SetPos(int x, int y)
{
	X = x;
	Y = y;
}

int Shoot::getPosX()
{
	return X;
}

int Shoot::getPosY()
{
	return Y;
}

void Shoot::setShoted(bool val)
{
	shoted = val;
}

std::vector<std::vector<char>> Shoot::unDraw(std::vector<std::vector<char>> map)
{
	map[Y][X] = 0;
	return map;
}

std::vector<std::vector<char>> Shoot::draw(std::vector<std::vector<char>> map)
{
	map[Y][X] = 5;
	return map;
}

std::vector<std::vector<char>> Shoot::moveUp(std::vector<std::vector<char>> map)
{
	Y = Y - 1;
	map = draw(map);
	return map;
}

std::vector<std::vector<char>> Shoot::move(std::vector<std::vector<char>> map)
{
	map = unDraw(map);
	if (Y - 1 >= 0) {
		if (map[Y - 1][X] == 0) {
			map = moveUp(map);
		}
		else {
			hitSomthing = true;
			selfDestruct = true;
			return map;
		}
	}
	else
		selfDestruct = true;
	map = draw(map);
	return map;
}