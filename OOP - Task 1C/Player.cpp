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

bool Player::PurchaseGame(Game* game) {
	int cost = game->GetCost();

	if (credits >= cost) {
		RemoveCredits(cost);
		
		AddToLibrary(new LibraryItem(Date::CurrentDate(), game));
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
