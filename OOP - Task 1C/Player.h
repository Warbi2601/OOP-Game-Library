#pragma once

#include <string>
#include "LibraryItem.h"
#include "User.h"
#include <vector>
#include <algorithm>
#include "Game.h"

class Player : public User
{
	public:
		//Player(const std::string&, const std::string&, const Date&, double&);
		
		Player(const std::string & username, const std::string & password, const Date & created, const double & credits, List<Player*> friends);
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
		List<Player*> GetFriends() const;
		void AddFriend(Player* newFriend);
		bool RemoveFriend(string friendToDelete);
		void SellGameToFriend(Player* receivingFriend, LibraryItem* game);
		bool ownsGame(Game* game);

	private:
		vector<LibraryItem*> library;
		List<Player*> friends;
		double credits;
		void removeGameFromLibrary(LibraryItem*);
};
