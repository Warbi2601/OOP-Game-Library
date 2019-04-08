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
	Line(" ");

	if (app->IsUserLoggedIn())
	{
		Player* player = static_cast<Player*>(app->GetCurrentUser());
		if (player->ownsGame(game))
		{
			LibraryItem* item = player->getLibaryItem(game);
			Line("You own this game");
			Line("Date purchased: " + item->getDate().ToString(item->getDate()));
			Line("Play time: " + to_string(item->getTimePlayed()));
		}
		else
		{
			Line("Cost: " + to_string(game->GetCost()));
			Option('P', "Purchase game");
		}
	}

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
					
					if (success) Question("Congratulations! You now own " + game->GetName());
					else Question("You don't have enough credits!");

				}
			}
		} break;
	}

	return false;
}
