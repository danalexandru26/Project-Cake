#pragma once
#include"cake_carousel.hpp"
#include"cake_maker.hpp"
#include"Recipe.hpp"

class command_taker
{
public:
	command_taker() = default;

	cake take_command(recipe_cake recipe);
	std::vector<cake> take_command(recipe_cake recipe, std::size_t count);

	std::vector<cake> get_carousel_cakes();
	
	void check_carousel();
	void refill_carousel();

private:
	recipe_cake carousel_recipe;
	cake_maker maker;
	carousel cake_carousel;
};
