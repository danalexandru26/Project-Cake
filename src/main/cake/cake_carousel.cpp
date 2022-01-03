#include<cake/cake_carousel.hpp>


carousel::carousel()
	:low_limit{3}, max_capacity{12}
{
	std::fstream file("cakes.txt");
	std::string line;

	while (std::getline(file, line) && storage.size() < max_capacity)
	{
			storage.push_back(cake(line));
	}
}

bool carousel::add_cake(cake& recipe)
{
	if (storage.size() < max_capacity)
	{
		storage.push_back(recipe);
		return true;
	}
	return false;
}

cake carousel::get_cake(std::string recipe)
{
	if (storage.size() > low_limit)
	{
		for (auto it = storage.begin(); it != storage.end(); ++it)
		{
			if (it->get_recipe() == recipe)
			{
				it = storage.erase(it);
				return cake(recipe);
			}
		}
	}
	return cake();
}

std::size_t carousel::current_capacity()
{
	return storage.size();
}