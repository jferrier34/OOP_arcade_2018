/*
** EPITECH PROJECT, 2019
** $
** File description:
** core
*/

#include "core.hpp"

core::core(std::string name)
{
	void	*maker;

	this->hndl = dlopen(name.c_str(), RTLD_LAZY);
	if (!this->hndl) {
		std::cerr << "dlopen : " << dlerror() << std::endl;
		exit(84);
	}
	maker = dlsym(this->hndl, "make_circle");
	if (!maker) {
		std::cerr << "dlsym : " << dlerror() << std::endl;
		exit(84);
	}
	this->pMaker = (maker_circle)maker;
}

core::~core()
{
	dlclose(this->hndl);
}

void	core::loadGame(std::string name)
{
	void	*maker;
	this->hndlGame = dlopen(name.c_str(), RTLD_LAZY);
	if (!this->hndlGame) {
		std::cerr << "dlopen : " << dlerror() << std::endl;
		exit(84);
	}
	maker = dlsym(this->hndlGame, "make_game");
	if (!maker) {
		std::cerr << "dlsym : " << dlerror() << std::endl;
		exit(84);
	}
	this->pGame = (maker_game)maker;
}

Ilib	*core::getLib() const
{
	return this->pMaker();
}

Igame	*core::getGame() const
{
	return this->pGame();
}
