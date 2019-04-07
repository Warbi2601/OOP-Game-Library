#pragma once

#include <string>
#include "LibraryItem.h"
#include "User.h"
#include "ListT.h"
#include "Game.h"

class Player : public User
{
	public:
		Player(const std::string&, const std::string&, const Date&, double&);
		~Player();
		// Library
		List<LibraryItem*> GetLibrary() const;
		Player& AddToLibrary(LibraryItem* item);
		bool PurchaseGame(Game* game);
		// Credits
		double GetCredits() const;
		void AddCredits(double amount);
		void RemoveCredits(double amount);
		LibraryItem* getLibaryItem(Game* game);

		bool ownsGame(Game* game);
	private:
		List<LibraryItem*> library;
		double credits;
};