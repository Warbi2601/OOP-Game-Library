#pragma once

#include <string>
#include "Date.h"
#include "LibraryItem.h"
#include "ListT.h"

class User
{
	public:
		User(const std::string&, const std::string&, const Date&);
		
		virtual ~User();

		const std::string& GetUsername() const;
		const std::string& GetPassword() const;
		Date GetCreated() const;
	private:
		std::string username;
		std::string password;
		Date created;
		double credits;
};
