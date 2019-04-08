#include "Game.h"

Game::Game(int id, const std::string& name, const std::string& desc, int cost, int rating) : id(id), name(name), description(desc), cost(cost), ageRating(rating)
{
}

Game::~Game()
{
}

int Game::GetID() const 
{
	return id;
}

const std::string& Game::GetName() const
{
	return name;
}

const std::string& Game::GetDescription() const
{
	return description;
}

int Game::GetCost() const
{
	return cost;
}