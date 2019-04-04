#pragma once

#include <string>
#include "Player.h"

class Admin : public Player
{
	public:
		Admin(const string& , const string& , const Date&, double);
		~Admin();
};