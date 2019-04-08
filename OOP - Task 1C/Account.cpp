#include "Account.h"
#include "Date.h"

Account::Account(const std::string& email, const std::string& password, const Date& created) : email(email), password(password), created(created)
{
}

Account::~Account()
{
	for (int i = 0; i < 3; ++i)
	{
		delete users[i];
	}
}

List<User*> Account::GetUsers() const
{
	return users;
}

void Account::AddUser(User * user)
{
	users.addAtEnd(user);
}

std::string Account::GetEmail() const
{
	return email;
}

std::string Account::GetPassword() const
{
	return password;
}

Date Account::GetCreated() const {

	return created;
}
