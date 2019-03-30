//
// EPITECH PROJECT, 2018
// Arcade Game
// File description:
// Crate.cpp
//

#include "Include/Crate.hpp"

Crate::Crate()
{
	X = 0;
	Y = 0;
	life = 5;
}

Crate::~Crate()
{
}

void Crate::loseLife()
{
	life = life - 1;
}

void Crate::setPos(int x, int y)
{
	X = x;
	Y = y;
}

int Crate::getPosX()
{
	return X;
}

int Crate::getPosY()
{
	return Y;
}

int Crate::getLife()
{
	return life;
}

bool Crate::isDead()
{
	if (life <= 0)
		return true;
	else
		return false;
}