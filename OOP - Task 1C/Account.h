#pragma once

#include <string>
#include "Player.h"
#include "ListT.h"

class Account
{
	public:
		Account(const std::string&, const std::string&, const Date&);
		~Account();
		List<User*> GetUsers() const;
		void AddUser(User* user);

		std::string GetEmail() const;
		std::string GetPassword() const;
		Date GetCreated() const;
	private:
		std::string email;
		std::string password;
		Date created;
		List<User*> users;
};