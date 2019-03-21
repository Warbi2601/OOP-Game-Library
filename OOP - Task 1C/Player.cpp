#include "Player.h"

Player::Player(const std::string& username, const std::string& password, const std::string& created) : User(username, password, created)
{
}

Player::~Player()
{
	for (int i = 0; i < 2; ++i)
	{
		delete library[i];
	}
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
