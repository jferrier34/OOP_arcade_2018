##
## EPITECH PROJECT, 2019
## OOP_arcade_2018
## File description:
## Makefile
##


all	:	
	make -C ./lib
	make -C ./games
	make -C ./core

.PHONY : all

graphicals:
	make -C ./lib

games:
	make -C ./games

core:
	make -C ./core

all:
	make -C ./lib
	make -C ./games
	make -C ./core

clean:
	make clean -C ./lib
	make clean -C ./games
	make clean -C ./core

fclean:
	make fclean -C ./lib
	make fclean -C ./games
	make fclean -C ./core

re: fclean all

.PHONY: core games graphicals all clean fclean re