//
// EPITECH PROJECT, 2018
// Arcade Game
// File description:
// monster.hpp
//

#ifndef MONSTER_HPP_
	#define MONSTER_HPP_
	#include "MonsterPart.hpp"
	#include <vector>
	#include <iostream>

	class Monster
	{
	public:
		Monster();
		~Monster();
		void BasicSpawn(int sizeToSet, int Xpoint);
		void splitSpawn(Monster old, int id);
		int getSize();
		std::vector<std::vector<char>> moove(std::vector<std::vector<char>> map);
		void moveFullBody(int x, int y);
		std::vector<std::vector<char>> undraw(std::vector<std::vector<char>> map);
		std::vector<std::vector<char>> draw(std::vector<std::vector<char>> map);
		bool isTouchPlayer();
		bool isTouchBottomScreen();
		bool canMoveRight(std::vector<std::vector<char>> map);
		bool canMoveLeft(std::vector<std::vector<char>> map);
		int findIdFromCoord(int x, int y);
		std::vector<std::vector<char>> destroyHead(std::vector<std::vector<char>> map);
		bool isDead();
		bool isMaster();
	private:
		int size;
		bool moved;
		bool touchPlayer;
		bool touchBottomScreen;
		bool direction;
		bool dead;
		bool master;
		std::vector<MonsterPart> parts;
		std::vector<std::vector<char>> moveRight(std::vector<std::vector<char>> map);
		std::vector<std::vector<char>> moveLeft(std::vector<std::vector<char>> map);
		std::vector<std::vector<char>> moveDown(std::vector<std::vector<char>> map);
		std::vector<std::vector<char>> unlock(std::vector<std::vector<char>>);
	};
#endif
