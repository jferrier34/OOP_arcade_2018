//
// EPITECH PROJECT, 2018
// Arcade Game
// File description:
// centipede.cpp
//

#include "Include/centipede.hpp"

Centipede::Centipede()
{
	player.push_back(0);
	player.push_back(0);
	centipedeKilled = 0;
	score = 0;
	gameOver = false;
}

Centipede::~Centipede()
{
}

int	Centipede::getGameover()
{
	if (gameOver)
		return 1;
	return 0;
}

int	Centipede::getScore()
{
	return score;
}

bool Centipede::getWin()
{
	return win;
}

int Centipede::generateBasicCrate()
{
	if (std::experimental::randint(0, 100) <= 15)
		return 3;
	else
		return 0;
}

void Centipede::createCrateList()
{
	unsigned int i = 0;
	unsigned int j = 0;
	Crate tmp;

	while (i < map.size() - 1) {
		while (j < map[i].size() - 1) {
			if (map[i][j] == 3) {
				tmp.setPos(j,i);
				crateList.push_back(tmp);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void Centipede::generateBasicPlace(int sizeX, int sizeY)
{
	int i = 0;
	int j = 0;
	std::vector<char> temp;

	if (map.size() != 0)
		return;
	while (i < sizeY) {
		while (j < sizeX) {
			if (i < sizeY - 2)
				temp.push_back(generateBasicCrate());
			else
				temp.push_back(0);
		j++;
		}
		j = 0;
		i++;
		map.push_back(temp);
		temp.clear();
	}
	map[map.size() - 1][sizeX / 2] = 4;
	setPlayerPos(sizeX / 2, map.size() - 1);
	createCrateList();
}

void Centipede::setPlayerPos(int x, int y)
{
	player[0] = x;
	player[1] = y;
}

void Centipede::setMap(std::vector<std::vector<char>> new_map)
{
	map = new_map;
}

std::vector<std::vector<char>> Centipede::getMap()
{
	return map;
}

void Centipede::printMap()
{
	unsigned int i = 0;
	unsigned int j = 0;

	while (i < map.size()) {
		while(j < map[i].size())
			std::cout << map[i][j++] + 0;
		i++;
		j = 0;
		std::cout << std::endl;
	}
	std::cout << "\n\n";
}

int Centipede::findNewSpawn()
{
	int limit = 0;
	int tmp = 0;
	int tmp2 = 0;

	while (limit < 500) {
		std::experimental::randint(0, 100);
		tmp2 = map[0].size();
		tmp = std::experimental::randint(0, tmp2);
		if (map[0][tmp] == 0)
			return tmp;
		limit++;
	}
	return -1;
}

void Centipede::drawCrate()
{
	int i = 0;

	while (i < (int)crateList.size()) {
		map[crateList[i].getPosY()][crateList[i].getPosX()] = 3;
		i++;
	}
}

void Centipede::undrawCrate()
{
	int i = 0;

	while (i < (int)crateList.size()) {
		map[crateList[i].getPosY()][crateList[i].getPosX()] = 0;
		i++;
	}
}

void Centipede::updateCrate()
{
	undrawCrate();
	drawCrate();
}

void Centipede::nextStep()
{
	int i = 0;
	Monster mob;

	updateCrate();
	if (mobList.empty()) {
		mob.BasicSpawn(4, findNewSpawn());
		map = mob.draw(map);
		mobList.push_back(mob);
	}
	while (i < (int)mobList.size()) {
		map = mobList[i].moove(map);
		if (mobList[i].isTouchBottomScreen())
		{
			score -= 500;
			mobList.erase(mobList.begin() + i);
		}
		if (mobList[i].isTouchPlayer())
			gameOver = true;
		i++;
	}
}

void Centipede::hitCrate()
{
	int i = 0;

	while (i < (int)crateList.size()) {
		if (crateList[i].getPosY() == bullet.getPosY() - 1 &&
		    crateList[i].getPosX() == bullet.getPosX()) {
			crateList[i].loseLife();
			if (crateList[i].isDead()) {
				map[crateList[i].getPosY()][crateList[i].getPosX()] = 0;
				crateList.erase(crateList.begin() + i);
			}
		}
		i++;
	}
}

int Centipede::getTouchedMonster(int x, int y)
{
	int i = 0;

	while (i < (int)mobList.size()) {
		if (mobList[i].findIdFromCoord(x, y) != -1)
			return i;
		i++;
	}
	return -1;
}

void Centipede::hitMonster()
{
	int monster = getTouchedMonster(bullet.getPosX(), bullet.getPosY() - 1);
	Monster tmp;
	Crate tmp2;

	if (map[bullet.getPosY() - 1][bullet.getPosX()] == 1) {
		map = mobList[monster].destroyHead(map);
		if (mobList[monster].isDead()) {
			mobList.erase(mobList.begin() + monster);
			if (mobList[monster].isMaster())
				centipedeKilled += 1;
		}
	}
	else {
		map = mobList[monster].undraw(map);
		tmp.splitSpawn(mobList[monster], mobList[monster].findIdFromCoord(bullet.getPosX(), bullet.getPosY() - 1));
		tmp2.setPos(bullet.getPosX(), bullet.getPosY() - 1);
		crateList.push_back(tmp2);
		map = mobList[monster].draw(map);
		map = tmp.draw(map);
		updateCrate();
		mobList.push_back(tmp);
	}
}

void Centipede::shootNextStep()
{
	if (bullet.isShoted()) {
		map = bullet.move(map);
		if (bullet.isHitSomthing()) {
			if (map[bullet.getPosY() - 1][bullet.getPosX()] == 3) {
				hitCrate();
				score += 5;
			}
		}
		if (bullet.isSelfDestruct())
			map = bullet.reset(map);
	}
}

void Centipede::drawPlayer()
{
	map[player[1]][player[0]] = 4;
}

void Centipede::undrawPlayer()
{
	map[player[1]][player[0]] = 0;
}

void Centipede::playerMoveUp()
{
	if (player[1] - 1 < 0)
		return;
	undrawPlayer();
	if (map[player[1] - 1][player[0]] == 0)
		player[1] = player[1] - 1;
	else if (map[player[1] - 1][player[0]] == 1 || map[player[1] - 1][player[0]] == 2)
		gameOver = true;
}

void Centipede::playerMoveDown()
{
	if (player[1] + 1 > ((int)map.size() * 20 / 100 ))
		return;
	undrawPlayer();
	if (map[player[1] + 1][player[0]] == 0)
		player[1] = player[1] + 1;
	else if (map[player[1] + 1][player[0]] == 1 || map[player[1] + 1][player[0]] == 2)
		gameOver = true;
	drawPlayer();
	drawPlayer();
}

void Centipede::playerMoveRight()
{
	if (player[0] + 1 > (int)map[0].size())
		return;
	undrawPlayer();
	if (map[player[1]][player[0] + 1] == 0)
		player[0] = player[1] + 1;
	else if (map[player[1]][player[0] + 1] == 1 || map[player[1]][player[0] + 1] == 2)
		gameOver = true;
	drawPlayer();
}

void Centipede::playerMoveLeft()
{
	if (player[0] - 1 < 0)
		return;
	undrawPlayer();
	if (map[player[1]][player[0] - 1] == 0)
		player[0] = player[1] - 1;
	else if (map[player[1]][player[0] - 1] == 1 || map[player[1]][player[0] - 1] == 2)
		gameOver = true;
	drawPlayer();
}

void Centipede::playerShot()
{
	if (bullet.isShoted() == false) {
		if (map[player[1] - 1][player[0]] != 0) {
			bullet.SetPos(player[0], player[1]);
			bullet.setShoted(true);
			if (map[player[1] - 1][player[0]] == 2  || map[player[1] - 1][player[0]] == 1) {
				hitMonster();
				score += 100;
			}
			else if (map[player[1] - 1][player[0]] == 3) {
				hitCrate();
				score += 50;
			}
			map = bullet.reset(map);
			drawPlayer();
			return;
		}
		else {
			bullet.SetPos(player[0], player[1] - 1);
			bullet.setShoted(true);
		}
		map = bullet.draw(map);
	}
}

int Centipede::initMap(int, int)
{
	gameOver = false;
	win = false;
	centipedeKilled = 0;
	score = 0;
	duration = 0;
	shootDuration = 0;
	generateBasicPlace(30, 10);
	return 0;
}

void Centipede::restart()
{
	mobList.erase(mobList.begin(), mobList.end());
	map.erase(map.begin(), map.end());
	crateList.erase(crateList.begin(), crateList.end());
	initMap(0, 0);
}

void Centipede::touchKey(int value)
{
	switch (value) {
	case 0:
		playerMoveUp();
		break;
	case 1:
		playerMoveDown();
		break;
	case 2:
		playerMoveLeft();
		break;
	case 3:
		playerMoveRight();
		break;
	case 5:
		restart();
		break;
	case 11:
		playerShot();
		break;
	}
}

int Centipede::game()
{
	if (map.empty())
		initMap(0, 0);
	nextStep();
	shootNextStep();
	if (centipedeKilled >= 20) {
		win = true;
		return 1;
	}
	return 0;
}

extern "C"
{
	Igame *make_game()
	{
		return new Centipede();
	}
}