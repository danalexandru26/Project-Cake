#include<iostream>
#include<random>
#include<cake/command_panel.hpp>

std::string determine();
void timer(std::size_t index);

int main()
{
	command_panel panel;

	while (true)
	{
		for (std::size_t i = 0; i < 10; ++i)
		{
			timer(i);
			std::cout << determine() << '\n';
		}
	}

	return 0;
}

std::string determine()
{
	std::random_device seed;
	std::mt19937 gen(seed());

	std::string line;
	std::string result;

	std::ifstream file("menu.txt");

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

void timer(std::size_t index)
{
	using namespace std::this_thread;
	using namespace std::chrono;
	using namespace std::chrono_literals;
	using std::chrono::system_clock;

	std::cout << "Customer " << index << " picked ";
	sleep_until(system_clock::now() + 0.5s);
}
