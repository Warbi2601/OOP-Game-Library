#pragma once

#include "Menu.h"
#include "StoreMenu.h"
#include "Application.h"
#include "LibraryItem.h"
#include "LoginMenu.h"
#include "ProfileMenu.h"
#include "User.h"


class MainMenu : public Menu
{
	public:
		MainMenu(const std::string& title, Application * app);
		void OutputOptions() final;
		bool HandleChoice(char choice) final;
};