#pragma once
#include<cake/Recipe.hpp>
#include<chrono>
#include<thread>
#include<iostream>

struct cake_maker
{
	cake take_command(recipe_cake recipe);
};