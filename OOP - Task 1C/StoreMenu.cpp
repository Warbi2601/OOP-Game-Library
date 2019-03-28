#include "StoreMenu.h"
#include "GameMenu.h"

StoreMenu::StoreMenu(const std::string& title, Application * app, List<Game*> games) : gamesToDisplay(games), Menu(title, app)
{
	Paint(); // required in constructor
}

void StoreMenu::OutputOptions()
{
	Option('S', "Search the store");
	for (int i = 0; i < gamesToDisplay.length(); i++)
	{
		// adding 1 so the display is nicer for the user
		Option(i + 1, gamesToDisplay[i]->GetName());
	}
}

bool StoreMenu::HandleChoice(char choice)
{
	if (choice == 'S')
	{
		string searchQuery = Question("Enter search criteria: ");

		List<Game*> allGames = app->GetStore().GetGames();
		List<Game*> matchedGames;
		
		for (int i = 0; i < allGames.length(); i++)
		{
			Game* game = allGames[i];

			if (Utils::StartsWith(searchQuery, game->GetName()))
			{
				matchedGames.addAtEnd(game);
			}
		}

		StoreMenu("Store", app, matchedGames);
	}
	// since we are using numbers here we shift the char down by '1'
	// this puts '1' as 0, '2' as 1, '3' as 2, '4' as 3, etc.
	// this reverses the + 1 above and lets us do the range check below
	int index = choice - '1';
	Game* selected = app->GetStore().GetGames()[index];

	if (index >= 0 && index < app->GetStore().GetGames().length())
	{
		GameMenu(selected->GetName(), app, selected);
	}

	return false;
}