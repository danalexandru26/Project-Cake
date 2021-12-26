#pragma once
#include<string>


struct cake
{
	std::string recipe;

	cake();
	cake(std::string recipe);

	std::string get_recipe();

};