#include "User.h"

User::User(const std::string& username, const std::string& password, const Date& created) : username(username), password(password), created(created)
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

Date User::GetCreated() const {

	return created;
}