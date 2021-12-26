#include<cake/command_panel.hpp>

command_panel::command_panel(std::string path)
	:taker{}
{
	std::fstream file(path);
	std::string line;

	while (std::getline(file, line))
	{
		std::istringstream stream(line);
		std::string recipe;
		std::size_t time;

		if (stream >> recipe >> time)
		{
			menu.push_back(recipe_cake(recipe, time));
		}
	}
}

void command_panel::show_products()
{
	for (auto& recipe : menu)
	{
		std::cout << "Name: " << recipe.get_recipe() << ' ' << "Time: " << recipe.get_time() << '\n';

	}
}

void command_panel::select_product(std::string recipe)
{
	auto it = menu.begin();
	auto c = std::find_if(menu.begin(), menu.end(), [&](const recipe_cake& c) {return c.recipe == recipe;});

	taker.take_command(*c);
}

void command_panel::carousel_products()
{
	auto list = taker.get_carousel_cakes();

	for (auto& cake : list)
	{
		std::cout << cake.get_recipe() << ' ';
	}
	std::cout << '\n';
}