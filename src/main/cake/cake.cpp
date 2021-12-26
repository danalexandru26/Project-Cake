#include<cake/cake.hpp>

cake::cake()
	:recipe{ "cookie dough" }
{}

cake::cake(std::string recipe)
	: recipe{ recipe }
{}

std::string cake::get_recipe()
{
	return recipe;
}