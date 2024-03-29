#pragma once

#include <string>

class Game
{
	public:
		Game(int,const std::string&, const std::string&, int, int);
		~Game();
		int GetID() const;
		const std::string& GetName() const;
		const std::string& GetDescription() const;
		int GetCost() const;
		int GetRating() const;
	private:
		int id;
		std::string name;
		std::string description;
		int cost;
		int ageRating;
};