//
// EPITECH PROJECT, 2018
// Arcade Games
// File description:
// centipede.hpp
//

#ifndef CENTIPEDE_HPP_
	#define CENTIPEDE_HPP_
	#include <iostream>
	#include <experimental/random>
	#include <vector>
	#include <ctime>
	#include "monster.hpp"
	#include "shoot.hpp"
	#include "Crate.hpp"
	#include "Igame.hpp"

	class Centipede : public Igame
	{
	public:
		Centipede();
		~Centipede();
		int game();
		int getScore();
		std::vector<std::vector<char>> getMap();
		bool getWin();
		void playerShot();
		void touchKey(int value);
		int initMap(int, int);
		int getGameover();
		void printMap();
	private:
		void nextStep();
		void playerMoveUp();
		void playerMoveDown();
		void playerMoveRight();
		void playerMoveLeft();
		void shootNextStep();
		int findNewSpawn();
		void createCrateList();
		void updateCrate();
		void drawCrate();
		void undrawCrate();
		void hitCrate();
		void hitMonster();
		int getTouchedMonster(int x, int y);
		void restart();
		void drawPlayer();
		void undrawPlayer();
		int generateBasicCrate();
		void setMap(std::vector<std::vector<char>> new_map);
		void setPlayerPos(int x, int y);
		void generateBasicPlace(int sizeX, int sizeY);
		std::vector<std::vector<char>> map;
		std::vector<int> player;
		std::vector<Monster> mobList;
		std::vector<Crate> crateList;
		Shoot bullet;
		std::clock_t monsterStep;
		std::clock_t shootStep;
		double shootDuration;
		double duration;
		int centipedeKilled;
		int score;
		bool gameOver;
		bool win;
	};
#endif
