#pragma once

#include <string>

class Game
{
	public:
		Game(const std::string&, const std::string&, int, int);
		~Game();

		const std::string& GetName() const;
		const std::string& GetDescription() const;
		int GetCost() const;
		bool BuyGame(); //TODO - implement function
	private:
		std::string name;
		std::string description;
		int cost;
		int ageRating;
};