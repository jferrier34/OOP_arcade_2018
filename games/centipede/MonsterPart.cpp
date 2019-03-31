//
// EPITECH PROJECT, 2018
// Arcade Game
// File description:
// MonsterPart.cpp
//

#include "Include/MonsterPart.hpp"

MonsterPart::MonsterPart()
{
	id = 0;
	X = 0;
	Y = 0;
	head = false;
}

MonsterPart::~MonsterPart()
{
}

int MonsterPart::getX()
{
	return X;
}

int MonsterPart::getY()
{
	return Y;
}

bool MonsterPart::getHead()
{
	return head;
}
int MonsterPart::getId()
{
	return id;
}

void MonsterPart::setX(int Xval)
{
	X = Xval;
}

void MonsterPart::setY(int Yval)
{
	Y = Yval;
}

void MonsterPart::setHead(bool headval)
{
	head = headval;
}

void MonsterPart::setId(int idval)
{
	id = idval;
}