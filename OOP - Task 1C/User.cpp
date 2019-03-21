#include "User.h"

User::User(const std::string& username, const std::string& password, const std::string& created) : username(username), password(password), created(created)
{
}

User::~User()
{
}

const std::string& User::GetUsername() const
{
	return username;
}

const std::string & User::GetPassword() const
{
	return password;
}

List<LibraryItem*> User::GetLibrary() const
{
	return library;
}

Player& User::AddToLibrary(LibraryItem * item)
{
	library.addAtEnd(item);
	return *this;
}