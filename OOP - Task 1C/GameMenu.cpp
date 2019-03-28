#include "GameMenu.h"
#include "LoginMenu.h"

using namespace std;

GameMenu::GameMenu(const std::string& title, Application * app, Game* game) : Menu(title, app), game(game)
{
	Paint(); // required in constructor
}

void GameMenu::OutputOptions()
{
	assert(game != nullptr);

	Line(game->GetDescription());
	Line("Cost: " + game->GetCost());

	Option('P', "Purchase game");
}

bool GameMenu::HandleChoice(char choice)
{
	switch (choice)
	{
		case 'P':
		{
			if (app->IsPlayer())
			{
				std::string answer = Question("Are you sure?");
				if (answer == "y" || answer == "Y")
				{
					Player* player = dynamic_cast<Player*>(app->GetCurrentUser());
					bool success = player->PurchaseGame(game);
					cout << success;
					// Remove cost
					// game.GetCost();
				}
			}
			else
			{
				// this would need to go to a LoginMenu - similar to StoreMenu
				// instead we just set logged in to true on the main app object

				//app->LogIn();
			}
		} break;
	}

	return false;
}
