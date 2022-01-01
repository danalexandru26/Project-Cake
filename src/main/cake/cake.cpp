#include<cake/cake.hpp>

cake::cake()
	:recipe{ "cookie dough" }
{}

inline cake::cake(std::string recipe)
	: recipe{ recipe }
{}

inline std::string cake::get_recipe()
{
	return recipe;
}