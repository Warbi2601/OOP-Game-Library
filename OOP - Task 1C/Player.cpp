#include "Player.h"

// I tried to put this in Utils and declare them as static
// but he compiler wasn't having any of it -Marcus
struct {
	bool operator()(LibraryItem* a, LibraryItem* b) const
	{
		// This was throwing an error, so I'll just return false...
		// return a->getDate() < b->getDate();
		return false;
	}
} compareDates;
struct {
	bool operator()(LibraryItem* a, LibraryItem* b) const
	{
		// This works perfectly
		return a->getGame()->GetName() < b->getGame()->GetName();
	}
} compareNames;

Player::Player(const std::string& username, const std::string& password, const Date& created,const double& credits) : User(username, password, created, credits)
{

}

Player::~Player()
{

	//for (int i = 0; i < 2; ++i)
	//{
	//	delete library[i];
	//}
}

vector<LibraryItem*> Player::GetLibrary() const
{
	return library;
}

Player& Player::AddToLibrary(LibraryItem * item)
{
	library.push_back(item);
	return *this;
}

void Player::SortLibrary(std::string type)
{
	if (library.size() > 1) {
		if (type == "date") {
			std::sort(library.begin(), library.end(), compareDates);
		}
		else if (type == "name") {
			std::sort(library.begin(), library.end(), compareNames);
		}
	}
}

bool Player::PurchaseGame(Game* game)
{
	int cost = game->GetCost();

	if (credits >= cost)
	{
		RemoveCredits(cost);

		AddToLibrary(new LibraryItem(Date::CurrentDate(), game,0));
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
	for (int i = 0; i < library.size(); i++)
	{
		LibraryItem* item = library[i];
		if (item->getGame() == game) return true;
	}
	return false;
}

LibraryItem* Player::getLibaryItem(Game* game)
{
	assert(library.size() > 0);

	for (int i = 0; i < library.size(); i++)
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
