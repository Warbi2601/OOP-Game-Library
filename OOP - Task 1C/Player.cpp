#include "Player.h"

Player::Player(const std::string& username, const std::string& password, const Date& created, double& credits) : User(username,password,created),credits(credits)
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

bool Player::PurchaseGame(Game* game) {
	int cost = game->GetCost();

	if (credits >= cost) {
		RemoveCredits(cost);
		
		AddToLibrary(new LibraryItem(Date::CurrentDate(), game,0));
		return true;
	}
	else {
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
