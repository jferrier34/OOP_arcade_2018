##
## EPITECH PROJECT, 2019
## OOP_arcade_2018
## File description:
## Makefile
##

RM		= rm -f

CXX		= g++ -g

CPPFLAGS	=	-I../lib/Include
CPPFLAGS	+=	-I../games

NAME	= ../arcade

SRCS	= core.cpp	\
	  main_tmp.cpp

OBJS	= $(SRCS:.cpp=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) $(CPPFLAGS) -o $(NAME) -ldl

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re