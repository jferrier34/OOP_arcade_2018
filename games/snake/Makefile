##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

RM		= rm -f

CXX		= g++ -shared -fPIC

CXXFLAGS	= -W -Wall -Wextra
CXXFLAGS	+= -I./include/

NAME		= ../Nibbler.so

SRCS		= snake.cpp	\
		  utils.cpp

ifeq ($(DEBUG), true)
CXXFLAGS	+= -g3
CXXFLAGS	+= -D__DEBUG__
endif

OBJS	= $(SRCS:.cpp=.o)

ifeq ($(VISUAL), true)
.cpp.o:
	@echo -ne "\e[96mCompilation of\e[93m" $(notdir $<) "\e[96m... \e[0m";
	@$(CXX) -c  -o $@ $< $(CXXFLAGS) 2> /dev/null &&	\
	echo -e "\e[92mSUCCESS\e[0m" ||			\
	echo -e "\e[91m\e[7mFAILURE\e[0m"

$(NAME): $(OBJS)
	@echo -ne "\e[34m\e[1mFinal Compilation ... "
	@$(CXX) -o $(NAME) $(OBJS) 2> /dev/null &&	\
	echo -e "\e[92mSUCCESS\e[0m" ||			\
	echo -e "\e[39m\e[41mFAILURE\e[0m"

all:	$(NAME)

clean:
	@$(RM) $(OBJS)
	@echo -e "\e[95mRemoving binaries files\e[0m"

fclean: clean
	@$(RM) $(NAME)
	@echo -e "\e[95mRemoving executable file\e[0m"
else
$(NAME): $(OBJS)
	$(CXX) -o $(NAME) $(OBJS)

all:	$(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
endif

re:	fclean all

.PHONY: all clean fclean re
