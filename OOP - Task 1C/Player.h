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
	private:
		List<LibraryItem*> library;
};