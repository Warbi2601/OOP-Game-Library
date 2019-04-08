#pragma once

#include "Menu.h"
#include "StoreMenu.h"
#include "Application.h"
#include "LibraryItem.h"
#include "LoginMenu.h"
#include "User.h"


class GiftFriendMenu : public Menu
{
	public:
		GiftFriendMenu(const std::string& title, Application * app, Player* sendingTo);
		void OutputOptions() final;
		bool HandleChoice(char choice) final;
	private:
		Player* sendingTo;
};