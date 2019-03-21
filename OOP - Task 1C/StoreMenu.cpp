#include "StoreMenu.h"

StoreMenu::StoreMenu(const std::string& title, Application * app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void StoreMenu::OutputOptions()
{
	List<Game*> games = app->GetStore().GetGames();

	for (int i = 0; i < games.length(); i++)
	{
		// adding 1 so the display is nicer for the user
		Option(i + 1, games[i]->GetName());
	}
}

bool StoreMenu::HandleChoice(char choice)
{
	// since we are using numbers here we shift the char down by '1'
	// this puts '1' as 0, '2' as 1, '3' as 2, '4' as 3, etc.
	// this reverses the + 1 above and lets us do the range check below
	int index = choice - '1';
	
	List<Game*> games = app->GetStore().GetGames();

	if (index >= 0 && index < games.length())
	{
		Game* game = games[index];
		GameMenu(game->GetName(), app, game);

		// Question("Not implemented, press return to continue (");
		// go to game detail page
	}

	return false;
}