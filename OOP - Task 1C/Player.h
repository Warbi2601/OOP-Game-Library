#pragma once

#include <string>
#include "LibraryItem.h"
#include "User.h"
#include <vector>
#include <algorithm>
#include "Utils.h"
#include "Game.h"

class Player : public User
{
	public:
		Player(const std::string&, const std::string&, const Date&);
		~Player();
		// Library
		vector<LibraryItem*> GetLibrary() const;
		Player& AddToLibrary(LibraryItem* item);
		void SortLibrary(std::string type);
		bool PurchaseGame(Game* game);
		// Credits
		double GetCredits() const;
		void AddCredits(double amount);
		void RemoveCredits(double amount);
		LibraryItem* getLibaryItem(Game* game);

		bool ownsGame(Game* game);
	private:
		vector<LibraryItem*> library;
		double credits;
};