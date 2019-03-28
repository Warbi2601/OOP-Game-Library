#pragma once

#include "Menu.h"
#include "Game.h"
#include "Utils.h"
#include "Player.h"

class GameMenu : public Menu
{
	public:
		GameMenu(const std::string& title, Application * app, Game* game);
		void OutputOptions() final;
		bool HandleChoice(char choice) final;
	private:
<<<<<<< HEAD
		Game* GameOnPage;
=======
		Game * game;
>>>>>>> Store
};