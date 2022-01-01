#include<iostream>
#include<random>
#include<cake/command_panel.hpp>

std::string determine(std::string const& path = "menu.txt");

int main()
{
	command_panel panel;

	while (true)
	{
		std::cout << "\nMenu products\n";
		panel.show_products();
		std::cout << "\nCarousel products\n";
		panel.carousel_products();
		std::string result = determine();
		std::cout << "\nCustomer picked : " << result <<'\n';
	}

	return 0;
}

std::string determine(std::string const& path)
{
	std::random_device seed;
	std::mt19937 gen(seed());

	std::string line;
	std::string result;

	std::ifstream file(path);

	for (std::size_t i = 0; std::getline(file, line); ++i)
	{
		std::uniform_int_distribution<> dist(0, i);
		if (dist(gen) < 1)
		{
			result = line;
		}
	}
	return result;
}