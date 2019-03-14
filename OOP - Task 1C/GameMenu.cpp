#include "GameMenu.h"

using namespace std;

GameMenu::GameMenu(const std::string& title, Application * app, Game* game) : Menu(title, app)
{
	Paint(); // required in constructor
}

void GameMenu::OutputOptions()
{
	Option('B', "Buy game");
}

bool GameMenu::HandleChoice(char choice)
{
	switch (choice)
	{
		case 'L':
		{
			if (app->IsUserLoggedIn())
			{
				std::string answer = Question("Are you sure?");
				if (answer == "y" || answer == "Y")
				{
					//app->LogOut();
				}
			}
			else
			{
				// this would need to go to a LoginMenu - similar to StoreMenu
				// instead we just set logged in to true on the main app object

				//app->LogIn();
			}
		} break;
		case 'P':
		{
			if (app->IsUserLoggedIn())
			{
				Question("Not implemented, press return to continue (");
				// this needs to go to a profile page - similar to StoreMenu
				// notice the if - this only works if somebody is logged in
			}
		} break;
	}

	return false;
}