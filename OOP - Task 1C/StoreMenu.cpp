#include "StoreMenu.h"

StoreMenu::StoreMenu(const std::string& title, Application * app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void StoreMenu::OutputOptions()
{
	Option('S', "Search the store");
	List<Game*> games = app->GetStore().GetGames();

	for (int i = 0; i < games.length(); i++)
	{
		// adding 1 so the display is nicer for the user
		Option(i + 1, games[i]->GetName());
	}
}

bool StoreMenu::HandleChoice(char choice)
{
	if (choice == 'S')
	{
		string search = Question("Enter search criteria: ");
		//app->GetStore().GetGames();
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
