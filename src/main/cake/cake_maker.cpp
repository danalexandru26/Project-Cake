#include<cake/cake_maker.hpp>

cake cake_maker::take_command(recipe_cake recipe)
{
	using namespace std::this_thread;
	using namespace std::chrono;
	using std::chrono::system_clock;

	std::cout << "\nMaking cake...\n";
	sleep_until(system_clock::now() + seconds(recipe.get_time()));

	return cake(recipe.get_recipe());
}