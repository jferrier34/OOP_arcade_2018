//
// EPITECH PROJECT, 2018
// Arcade Game
// File description:
// Crate.hpp
//

#ifndef CRATE_HPP_
	#define CRATE_HPP_

	class Crate
	{
	public:
		Crate();
		~Crate();
		void loseLife();
		void setPos(int x, int y);
		int getPosX();
		int getPosY();
		int getLife();
		bool isDead();
	private:
		int X;
		int Y;
		int life;
	};
#endif
