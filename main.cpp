#include<iostream>
#include<cake/command_panel.hpp>

int main()
{
	command_panel panel;
	panel.show_products();
	panel.carousel_products();

	return 0;
}