##
## EPITECH PROJECT, 2019
## OOP_arcade_2018
## File description:
## Makefile
##

RM		= rm -f

CXX		= g++ -shared -fPIC -g

CXXFLAGS	= -W -Wall -Wextra
CXXFLAGS	+= -I Include/

NAMENCURSE	= ../lib_arcade_ncurses.so

NAMESFML	= ../lib_arcade_sfml.so

NAMESDL	= lib_arcade_sdl.so

SRCSNCURSE	= Source/libncurses.cpp

SRCSSFML	= Source/libsfml.cpp

OBJSNCURSE	= $(SRCSNCURSE:.cpp=.o)

OBJSSFML	= $(SRCSSFML:.cpp=.o)

all:	$(NAMENCURSE) $(NAMESFML)

sfml:	$(NAMESFML)

ncurse:	$(NAMENCURSE)

$(NAMENCURSE): $(OBJSNCURSE)
	$(CXX) $(OBJSNCURSE) -o $(NAMENCURSE) -lncurses -ldl

$(NAMESFML): $(OBJSSFML)
	$(CXX) $(OBJSSFML) -o $(NAMESFML) -lsfml-graphics -lsfml-window -lsfml-system

clean:
	$(RM) $(OBJSNCURSE) $(OBJSSFML)

fclean: clean
	$(RM) $(NAMENCURSE) $(NAMESFML)

re:	fclean all

.PHONY: all clean fclean re
