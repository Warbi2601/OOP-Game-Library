#pragma once

#include "Menu.h"
#include "Game.h"

class GameMenu : public Menu
{
	public:
		GameMenu(const std::string& title, Application * app, Game* game);
		void OutputOptions() final;
		bool HandleChoice(char choice) final;
	private:
		Game* GameOnPage;
};