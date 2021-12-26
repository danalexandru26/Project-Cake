#include"command_taker.hpp"


class command_panel
{
public:
	command_panel(std::string path = "menu.txt");

	void show_products();
	void select_product(std::string recipe);
	void carousel_products();


private:
	std::vector<recipe_cake> menu;
	command_taker taker;
};