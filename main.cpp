#include<iostream>
#include<random>
#include<cake/command_panel.hpp>

void determine(std::string& cake, std::size_t& quantity);
void timer(std::size_t index);

int main()
{
	command_panel panel;

	std::string recipe;
	std::size_t quantity;

	std::vector<cake> multiple_order;
	cake single_order;

	panel.show_products();

	while (true)
	{
		for (std::size_t i = 0; i < 10; ++i)
		{
			determine(recipe, quantity);
			std::cout << "\nCustomer " << i << " picked " << recipe << " of quantity : " << quantity;
			timer(i);

			if (quantity)
			{
				try
				{
					multiple_order = panel.select_product(recipe, quantity);
					std::cout << "Order:\n";
					for (auto& recipe : multiple_order)
					{
						std::cout << recipe.get_recipe() << ' ';
					}
				}
				catch (const std::invalid_argument& e)
				{
					std::cout << "\nCake is not on the menu";
				}
			}
			else
			{
				try
				{
					single_order = panel.select_product(recipe);
					std::cout << single_order.get_recipe();
				}
				catch (const std::invalid_argument& e)
				{
					std::cout << "\nCake is not on the menu";
				}
			}
			std::cout << '\n';
		}
	}
}

void  determine(std::string& cake, std::size_t& quantity)
{
	std::random_device seed;
	std::mt19937 gen(seed());

	std::string recipe;
	std::string line;

	std::ifstream file("pick.txt");

	for (std::size_t i = 0; std::getline(file, line); ++i)
	{
		std::istringstream buffer(line);
		buffer >> recipe;

		std::uniform_int_distribution<> dist(0, i);
		
		if (dist(gen) < 1)
		{
			cake = recipe;
		}
	}

	std::uniform_int_distribution<> dist_2(1, 6);
	quantity = dist_2(gen);
}

void timer(std::size_t index)
{
	using namespace std::this_thread;
	using namespace std::chrono;
	using namespace std::chrono_literals;
	using std::chrono::system_clock;

	sleep_until(system_clock::now() + 0.5s);
}
