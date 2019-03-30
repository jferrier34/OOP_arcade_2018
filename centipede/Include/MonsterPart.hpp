//
// EPITECH PROJECT, 2018
// Arcade Game
// File description:
// MonsterPart.hpp
//

#ifndef MONSTERPART_HPP_
	#define MONSTERPART_HPP_

	class MonsterPart
	{
	public:
		MonsterPart();
		~MonsterPart();
		int getX();
		int getY();
		bool getHead();
		int getId();
		void setX(int Xval);
		void setY(int Yval);
		void setHead(bool headval);
		void setId(int idval);
	private:
		int X;
		int Y;
		bool head;
		int id;
	};
#endif
