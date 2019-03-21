#pragma once

#include <string>
#include "LibraryItem.h"
#include "User.h"
#include "ListT.h"

class Player : public User
{
	public:
		Player(const std::string&, const std::string&, const std::string&);
		~Player();
		List<LibraryItem*> GetLibrary() const;
		Player& AddToLibrary(LibraryItem* item);
	private:
		List<LibraryItem*> library;
};