/*
** EPITECH PROJECT, 2019
** utils.cpp
** File description:
** utils.cpp
*/

#include <experimental/random>
#include "snake.hpp"

int	my_rand(int min, int max)
{
	return std::experimental::randint(min, max);
}
