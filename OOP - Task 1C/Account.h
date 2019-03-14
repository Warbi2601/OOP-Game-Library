#pragma once

#include <string>
#include "Player.h"
#include "ListT.h"

class Account
{
	public:
		Account(const std::string&, const std::string&, const std::string&);
		~Account();
		List<User*> GetUsers() const;

		std::string GetEmail() const;
		std::string GetPassword() const;
	private:
		std::string email;
		std::string password;
		std::string created;  // TODO: replace with custom Date class, currently YYYY-MM-DD
		List<User*> users;
};