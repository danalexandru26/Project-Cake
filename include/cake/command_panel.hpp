#pragma once
#include<stdexcept>
#include"command_taker.hpp"

class command_panel
{
public:
	command_panel(std::string path = "menu.txt");

	void show_products();
	cake select_product(std::string recipe);
	std::vector<cake> select_product(std::string recipe, std::size_t count);
	void carousel_products();

private:
	std::vector<recipe_cake> menu;
	command_taker taker;
};