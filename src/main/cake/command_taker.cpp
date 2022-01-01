#include<cake/command_taker.hpp>

cake command_taker::take_command(recipe_cake recipe)
{
	cake verify = cake_carousel.get_cake(recipe.get_recipe());

	if(verify.get_recipe() != "cookie dough")
	{
		return verify;
	}
	else
	{
		return maker.take_command(recipe);
	}
}

std::vector<cake> command_taker::take_command(recipe_cake recipe, std::size_t  count)
{
	std::vector<cake> order;
	while (count)
	{
		order.push_back(maker.take_command(recipe));
		--count;
	}

	return order;
}

void command_taker::refill_carousel()
{
	if (cake_carousel.current_capacity() == cake_carousel.low_limit)
	{
		std::fstream file("cakes.txt");
		std::string line;

		while (std::getline(file, line))
		{
			if (!cake_carousel.add_cake(maker.take_command(recipe_cake(line, 5))))
			{
				return;
			}
		}
	}
}

std::vector<cake> command_taker::get_carousel_cakes()
{
	return cake_carousel.storage;
}

void command_taker::check_carousel()
{
	if (cake_carousel.current_capacity() == cake_carousel.low_limit)
	{
		refill_carousel();
	}
}