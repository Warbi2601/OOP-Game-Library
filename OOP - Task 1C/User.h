#pragma once

#include <string>
#include "LibraryItem.h"
#include "ListT.h"

class User
{
	public:
		User(const std::string&, const std::string&, const std::string&);
		virtual ~User();
		
		const std::string& GetUsername() const;
		const std::string& GetPassword() const;
		// Library
		List<LibraryItem*> GetLibrary() const;
		Player& AddToLibrary(LibraryItem* item);
	private:
		std::string username;
		std::string password;
		std::string created;  // TODO: replace with custom Date class, currently YYYY-MM-DD
		
		List<LibraryItem*> library;
};