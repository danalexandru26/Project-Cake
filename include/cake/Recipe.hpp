#pragma once
#include<cake/cake.hpp>

struct recipe_cake
{
	std::string recipe;
	std::size_t time;

	recipe_cake() = default;
	recipe_cake(std::string recipe, std::size_t time);

	std::string get_recipe();
	std::size_t get_time();
};