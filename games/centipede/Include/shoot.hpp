//
// EPITECH PROJECT, 2018
// Arcade Game
// File description:
// shoot.hpp
//

#ifndef SHOOT_HPP_
	#define SHOOT_HPP_
	#include <vector>
	#include <iostream>

	class Shoot
	{
	public:
		Shoot();
		~Shoot();
		void SetPos(int x, int y);
		int getPosX();
		int getPosY();
		void setShoted(bool val);
		std::vector<std::vector<char>> reset(std::vector<std::vector<char>> map);
		bool isShoted();
		std::vector<std::vector<char>> move(std::vector<std::vector<char>> map);
		std::vector<std::vector<char>> draw(std::vector<std::vector<char>> map);
		std::vector<std::vector<char>> unDraw(std::vector<std::vector<char>> map);
		std::vector<std::vector<char>> moveUp(std::vector<std::vector<char>> map);
		bool isHitSomthing();
		bool isSelfDestruct();
	private:
		bool shoted;
		bool selfDestruct;
		bool hitSomthing;
		int X;
		int Y;
	};
#endif
