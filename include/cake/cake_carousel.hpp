#pragma once
#include<cake/cake.hpp>
#include<fstream>
#include<vector>
#include<sstream>

class carousel
{
public:
	friend class command_taker;

	carousel();
	
	bool add_cake(cake& recipe);
	cake get_cake(std::string recipe);

	std::size_t current_capacity();

private:
	std::size_t max_capacity;
	std::size_t low_limit;
	std::vector<cake> storage;
};

