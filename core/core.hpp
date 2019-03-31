/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** core
*/

#ifndef CORE_HPP_
    #define CORE_HPP_

# include "Ilib.hpp"
# include "Igame.hpp"
# include <iostream>
# include <map>
# include <dlfcn.h>
# include <string.h>

class	core
{
private:
	void	*hndl;
	void	*hndlGame;
	maker_circle	pMaker;
	maker_game	pGame;
	std::map<int, std::string>	libsName;
public:
	core(std::string);
	~core();
	maker_circle	getPointer() const;
	Ilib	*getLib() const;
	Igame	*getGame() const;
	void	loadGame(std::string);
	void	loadLib(std::string);
};

#endif /* !CORE_HPP_ */
