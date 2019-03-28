#pragma once

#include "Menu.h"
#include "Game.h"

#include <string>
#include <vector>


class StoreMenu : public Menu
{
	public:
		StoreMenu(const std::string& title, Application * app, List<Game*> games);
		void OutputOptions() final;
		bool HandleChoice(char choice) final;
	private:
		List<Game*> gamesToDisplay;
};