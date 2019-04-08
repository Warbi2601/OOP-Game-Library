#include "FriendMenu.h"

FriendMenu::FriendMenu(const std::string& title, Application * app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void FriendMenu::OutputOptions()
{
	Player* player = static_cast<Player*>(app->GetCurrentUser());
	Option('A', "Add friend");
	Option('R', "Remove friend");

	Line("\nFriends list:");
	
}

bool FriendMenu::HandleChoice(char choice)
{
	Player* player = static_cast<Player*>(app->GetCurrentUser());

	switch (choice)
	{
		case 'A': //Add friend
		{
			Question("Enter username");
		} break;
		case 'R': //Remove friend
		{
			Question("Enter username");
		} break;

	}

	int index = choice - '1';

	if (index >= 0 && index < player->GetLibrary().length())
	{

	}
	return false;
}