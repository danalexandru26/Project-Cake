#include<cake/Recipe.hpp>

recipe_cake::recipe_cake(std::string recipe, std::size_t time)
	:recipe{recipe}, time{time}
{}

inline std::string recipe_cake::get_recipe()
{
	return recipe;
}

inline std::size_t recipe_cake::get_time()
{
	return time;
}