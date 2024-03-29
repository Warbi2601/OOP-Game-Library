#pragma once

#include "Menu.h"
#include "StoreMenu.h"
#include "Application.h"
#include "LibraryItem.h"
#include "LoginMenu.h"
#include "User.h"
#include "GiftFriendMenu.h"


class FriendMenu : public Menu
{
	public:
		FriendMenu(const std::string& title, Application * app);
		void OutputOptions() final;
		bool HandleChoice(char choice) final;
};