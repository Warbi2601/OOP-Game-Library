#pragma once

#include "Menu.h"
#include "StoreMenu.h"
#include "Application.h"
#include "LibraryItem.h"
#include "LoginMenu.h"


class ProfileMenu : public Menu
{
	public:
		ProfileMenu(const std::string& title, Application * app);
		void OutputOptions() final;
		bool HandleChoice(char choice) final;
};