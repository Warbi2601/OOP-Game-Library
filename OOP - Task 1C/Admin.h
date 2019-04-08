#pragma once

#include <string>
#include "Player.h"
#include "Admin.h"

class Admin : public Player
{
	public:
		Admin(const std::string & username, const std::string & password, const Date & created, double & credits, List<Player*> friends);
		~Admin();
};