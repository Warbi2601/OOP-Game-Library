#include "GameMenu.h"
#include "LoginMenu.h"

using namespace std;

GameMenu::GameMenu(const std::string& title, Application * app, Game* game) : GameOnPage(game), Menu(title, app)
{
	Paint(); // required in constructor
}

void GameMenu::OutputOptions()
{
	assert(GameOnPage != nullptr);

	Line(GameOnPage->GetDescription());
	Line("Cost:" + GameOnPage->GetCost());

	Option('P', "Buy game");
}

bool GameMenu::HandleChoice(char choice)
{
	switch (choice)
	{
		case 'P':
		{
			if (app->IsUserLoggedIn())
			{
				Question("Not implemented, press return to continue (");
				// this needs to add the game to the users account..
			}
		} break;
	}

	return false;
}