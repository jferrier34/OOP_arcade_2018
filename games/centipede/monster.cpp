//
// EPITECH PROJECT, 2018
// Arcade Game
// File description:
// monster.cpp
//

#include "Include/monster.hpp"

Monster::Monster()
{
	dead = false;
	master = false;
	moved = false;
	direction = true;
	touchPlayer = false;
	touchBottomScreen = false;
}

Monster::~Monster()
{
}

bool Monster::isMaster()
{
	return master;
}

int Monster::getSize()
{
	return size;
}

bool Monster::isTouchPlayer()
{
	return touchPlayer;
}

bool Monster::isTouchBottomScreen()
{
	return touchBottomScreen;
}

bool Monster::isDead()
{
	return dead;
}

void Monster::BasicSpawn(int sizeToSet, int Xpoint)
{
	int i = 0;
	size = sizeToSet;
	MonsterPart tmp;
	master = true;

	while (i < size) {
		if (i == 0)
			tmp.setHead(true);
		else
			tmp.setHead(false);
		tmp.setId(i);
		tmp.setY(-i);
		tmp.setX(Xpoint);
		parts.push_back(tmp);
		i++;
	}
	parts[0].setHead(true);
}

void Monster::splitSpawn(Monster old, int id)
{
	int i = id + 1;
	int nid = 0;
	MonsterPart tmp;

	while (i < old.getSize()) {
		tmp = old.parts[i];
		if (i == id + 1)
			tmp.setHead(true);
		tmp.setId(nid++);
		parts.push_back(tmp);
		i++;
	}
	while (old.parts.back().getId() != id)
		old.parts.pop_back();
	size = parts.size();
	parts[0].setHead(true);
	old.parts.pop_back();
}

std::vector<std::vector<char>> Monster::destroyHead(std::vector<std::vector<char>> map)
{
	int i = 0;
	MonsterPart tmp = parts[i];
	MonsterPart tmp2;

	map = undraw(map);
	if (parts.size() <= 1)
		dead = true;
	else {
		i++;
		while (i < (int)parts.size()) {
			tmp2 = parts[i];
			parts[i] = tmp;
			tmp = tmp2;
			i++;
		}
	}
	size = size - 1;
	parts.erase(parts.begin());
	parts[0].setHead(true);
	map = draw(map);
	return map;
}

int Monster::findIdFromCoord(int x, int y)
{
	int i = 0;
	while (i < (int)parts.size()) {
		if (parts[i].getX() == x && parts[i].getY() == y)
			return parts[i].getId();
		i++;
	}
	return -1;
}

void Monster::moveFullBody(int x, int y)
{
	int i = 0;
	int xBuffer = 0;
	int yBuffer = 0;
	int xBuffers = 0;
	int yBuffers = 0;

	while(i < (int)parts.size()) {
		if (i == 0) {
			xBuffer = parts[i].getX();
			yBuffer = parts[i].getY();
			parts[i].setX(x);
			parts[i].setY(y);
		}
		else {
			xBuffers = xBuffer;
			yBuffers = yBuffer;
			xBuffer = parts[i].getX();
			yBuffer = parts[i].getY();
			parts[i].setX(xBuffers);
			parts[i].setY(yBuffers);
		}
		i++;
	}
}

std::vector<std::vector<char>> Monster::undraw(std::vector<std::vector<char>> map)
{
	int i = 0;

	while (i < (int)parts.size()) {
		if (parts[i].getY() >= 0 && parts[i].getX() >= 0)
			map[parts[i].getY()][parts[i].getX()] = 0;
		i++;
	}
	return map;
}
std::vector<std::vector<char>> Monster::draw(std::vector<std::vector<char>> map)
{
	int i = 0;

	while (i < (int)parts.size()) {
		if (parts[i].getX() >= 0 && parts[i].getY() >= 0) {
			if (parts[i].getHead())
				map[parts[i].getY()][parts[i].getX()] = 1;
			else
				map[parts[i].getY()][parts[i].getX()] = 2;
		}
		i++;
	}
	return map;
}

std::vector<std::vector<char>> Monster::moveRight(std::vector<std::vector<char>> map)
{
	if (moved)
		return map;
	if (parts[0].getX() + 1 < (int)map[0].size()) {
		if (map[parts[0].getY()][parts[0].getX() + 1] == 4) {
			touchPlayer = true;
			moved = true;
			return map;
		}
		else if (map[parts[0].getY()][parts[0].getX() + 1] == 0) {
			map = undraw(map);
			moveFullBody(parts[0].getX() + 1, parts[0].getY());
			moved = true;
		}
		map = draw(map);
	}
	return map;
}

std::vector<std::vector<char>> Monster::moveLeft(std::vector<std::vector<char>> map)
{
	if (moved)
		return map;
	if (parts[0].getX() - 1 >= 0) {
		if (map[parts[0].getY()][parts[0].getX() - 1] == 4) {
			touchPlayer = true;
			moved = true;
			return map;
		}
		else if(map[parts[0].getY()][parts[0].getX() - 1] == 0) {
			map = undraw(map);
			moveFullBody(parts[0].getX() - 1, parts[0].getY());
			moved = true;
		}
		map = draw(map);
	}
	return map;
}

bool Monster::canMoveRight(std::vector<std::vector<char>> map)
{
	if (parts[0].getX() + 1 < (int)map[0].size()) {
		if (map[parts[0].getY()][parts[0].getX() + 1] == 0)
			return true;
	}
	return false;
}

bool Monster::canMoveLeft(std::vector<std::vector<char>> map)
{
	if (parts[0].getX() - 1 < (int)map[0].size()) {
		if (map[parts[0].getY()][parts[0].getX() - 1] == 0)
			return true;
	}
	return false;
}

std::vector<std::vector<char>> Monster::moveDown(std::vector<std::vector<char>> map)
{
	if (moved)
		return map;
	if (parts[0].getY() + 1 >= (int)map.size()) {
		touchBottomScreen = true;
		moved = true;
		return map;
	}
	if (map[parts[0].getY() + 1][parts[0].getX()] == 4) {
		touchPlayer = true;
		moved = true;
		return map;
	}
	else if(map[parts[0].getY() + 1][parts[0].getX()] == 0) {
		map = undraw(map);
		moveFullBody(parts[0].getX(), parts[0].getY() + 1);
		moved = true;
	}
	if (direction)
		direction = false;
	else
		direction = true;
	map = draw(map);
	return map;
}

std::vector<std::vector<char>> Monster::unlock(std::vector<std::vector<char>> map)
{

	map = undraw(map);
	moveFullBody(parts[0].getX(), parts[0].getY() + 1);
	moved = true;
	map = draw(map);
	return map;
}

std::vector<std::vector<char>> Monster::moove(std::vector<std::vector<char>> map)
{
	if (canMoveRight(map) && direction == true)
		map = moveRight(map);
	else {
		map = moveLeft(map);
		if (canMoveLeft(map))
			direction = false;
	}
	if (direction == false && canMoveLeft(map))
		map = moveLeft(map);
	else {
		map = moveRight(map);
		if (canMoveRight(map))
			direction = true;
	}
	map = moveDown(map);
	if (moved == false)
		map = unlock(map);
	moved = false;
	return map;
}