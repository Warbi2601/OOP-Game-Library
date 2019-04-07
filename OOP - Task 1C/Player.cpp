#include "Player.h"

Player::Player(const std::string& username, const std::string& password, const Date& created) : User(username, password, created)
{
}

Player::~Player()
{

	//for (int i = 0; i < 2; ++i)
	//{
	//	delete library[i];
	//}
}

List<LibraryItem*> Player::GetLibrary() const
{
	return library;
}

Player& Player::AddToLibrary(LibraryItem * item)
{
	library.addAtEnd(item);
	return *this;
}

bool Player::PurchaseGame(Game* game) 
{
	int cost = game->GetCost();
	
	if (credits >= cost)
	{
		RemoveCredits(cost);
		AddToLibrary(new LibraryItem(Date::CurrentDate(), game));
		return true;
	}
	else
	{
		// Not enough credits!
		return false;
	}
}

double Player::GetCredits() const
{
	return credits;
}

void Player::AddCredits(double amount)
{
	assert(amount > 0);
	credits += amount;
}

void Player::RemoveCredits(double amount)
{
	assert(amount > 0);
	credits -= amount;
	
	if (credits < 0) {
		credits = 0;
	}
}

bool Player::ownsGame(Game * game)
{
	for (int i = 0; i < library.length(); i++)
	{
		LibraryItem* item = library[i];
		if (item->getGame() == game) return true;
	}
	return false;
}

LibraryItem* Player::getLibaryItem(Game* game)
{
	assert(library.isEmpty() == false);

	for (int i = 0; i < library.length(); i++)
	{
		LibraryItem* item = library[i];
		if (item->getGame() == game) return item;
	}
	return nullptr;
}

List<Player*> Player::GetFriends() const
{
	return friends;
}

void Player::AddFriend(Player* newFriend) {
	friends.addAtEnd(newFriend);
}

void Player::SellGameToFriend(Player* receivingFriend, LibraryItem* game)
{
	// Swaps the game owner
	removeGameFromLibrary(game);
	receivingFriend->AddToLibrary(game);

	//Handles the credits transaction
	double gameCost = (game->getGame()->GetCost()) / 2;
	credits += gameCost;
	receivingFriend->AddCredits(gameCost);
}

void Player::removeGameFromLibrary(LibraryItem* gameToRemove)
{
	library.deleteOne(gameToRemove);
}