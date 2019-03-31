/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** main
*/

#include "Ilib.hpp"
#include "libncurses.hpp"
#include "libsfml.hpp"
#include "core.hpp"
#include <string.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	int	t;
	int	pause = 0;
	std::string	libName;
	std::string	libGame;
	if (ac != 2) {
		std::cerr << "Usage : ./arcade ./lib_arcade_ncurses/sfml.so" << std::endl;
		return 84;
	}

	core	*point = new core(av[1]);
	int	i = 0;
	Ilib	*lib = point->getLib();
	Igame	*game = NULL;
	if (lib->menuGame()) {
		libName.assign(lib->getLibName());
		libGame.assign(lib->getGameName());
		lib->destroy();
		delete lib;
		delete point;
		point = new core(libName);
		point->loadGame(libGame);
		lib = point->getLib();
		game = point->getGame();
		game->initMap(10, 10);
		lib->setMap(game->getMap());
		while (!game->getGameover()) {
			usleep(300000);
			if (!pause) game->game();
			lib->setMap(game->getMap());
			lib->setScore(game->getScore());
			lib->printMap();
			lib->refreshWindow();
			t = lib->getchWindow();
			if (t == MENU) {
				if (lib->menuGame()) {
					libName.assign(lib->getLibName());
					libGame.assign(lib->getGameName());
					lib->destroy();
					delete lib;
					delete point;
					point = new core(libName);
					point->loadGame(libGame);
					lib = point->getLib();
					game = point->getGame();
					game->initMap(10, 10);
					lib->setMap(game->getMap());
				}
			}
			if (t == RESTART) {
				lib->destroy();
				delete lib;
				delete point;
				point = new core(libName);
				point->loadGame(libGame);
				lib = point->getLib();
				game = point->getGame();
				game->initMap(10, 10);
				lib->setMap(game->getMap());
			}
			if (t == BREAK) pause = !pause;
			if (t == -2) break;
			game->touchKey(t);
		}
	}
	lib->destroy();
	delete lib;
	return 0;
}
