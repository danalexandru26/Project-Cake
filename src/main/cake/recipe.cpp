#include<cake/Recipe.hpp>

recipe_cake::recipe_cake(std::string recipe, std::size_t time)
	:recipe{recipe}, time{time}
{}

std::string recipe_cake::get_recipe()
{
	return recipe;
}

std::size_t recipe_cake::get_time()
{
	return time;
}