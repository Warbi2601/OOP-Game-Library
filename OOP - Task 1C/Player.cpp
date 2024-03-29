#include "Player.h"
#include "Utils.h"

struct {
	bool operator()(LibraryItem* a, LibraryItem* b) const
	{
		return a->getDate() < b->getDate();
	}
} compareDates;
struct {
	bool operator()(LibraryItem* a, LibraryItem* b) const
	{
		return a->getGame()->GetName() < b->getGame()->GetName();
	}
} compareNames;

Player::Player(const std::string& username, const std::string& password, const Date& created, const double& credits, List<Player*>friends) : User(username, password, created), credits(credits), friends(friends)
{

}

Player::~Player()
{
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

bool Player::SellGameToFriend(Player* receivingFriend, LibraryItem* game)
{
	double gameCost = (game->getGame()->GetCost()) / 2;

	if(receivingFriend->GetCredits() > gameCost)
	{
		// Swaps the game owner
		removeGameFromLibrary(game);
		receivingFriend->AddToLibrary(game);

		//Handles the credits transaction
		credits += gameCost;
		receivingFriend->RemoveCredits(gameCost);
		return true;
	}
	return false;
}

void Player::removeGameFromLibrary(LibraryItem* gameToRemove)
{
	for (int i = 0; i < library.size(); i++)
	{
		if (library.at(i) == gameToRemove)
		{
			library.erase(library.begin() + i);
		}
	}
}

bool Player::RemoveFriend(string friendToDelete)
{
	Utils::ToUpper(friendToDelete);
	Player* player = static_cast<Player*>(this);

	if (!player->GetFriends().isEmpty())
	{
		for (int i = 0; i < player->GetFriends().length(); i++)
		{
			string foundUsername = player->GetFriends()[i]->GetUsername();
			Utils::ToUpper(foundUsername);

			if (foundUsername == friendToDelete)
			{
				friends.deleteOne(player->GetFriends()[i]);
				return true;
			}
		}
	}
	return false;
}