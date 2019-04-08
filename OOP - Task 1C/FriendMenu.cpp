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

	if (!player->GetFriends().isEmpty())
	{
		Line("\nFriends list:");
		for (int i = 0; i < player->GetFriends().length(); i++)
		{
			Option(i, player->GetFriends()[i]->GetUsername());
		}
	}
	else Line("You dont have any friends yet.");
}

bool FriendMenu::HandleChoice(char choice)
{
	Player* player = static_cast<Player*>(app->GetCurrentUser());

	switch (choice)
	{
		case 'A': //Add friend
		{
			string usernameSearch = Question("Enter username");

			Utils::ToUpper(usernameSearch);
			bool flag = false;
			for (int acc = 0; acc < app->GetAccounts().length(); acc++)
			{
				for (int usr = 0; usr < app->GetAccounts()[acc]->GetUsers().length(); usr++)
				{
					string foundUsername = app->GetAccounts()[acc]->GetUsers()[usr]->GetUsername();
					Utils::ToUpper(foundUsername);
					if (foundUsername == usernameSearch)
					{
						Player* temp = static_cast<Player*>(app->GetAccounts()[acc]->GetUsers()[usr]);
						player->AddFriend(temp);
						flag = true;
					}
				}
			}
			if (!flag) Question("No user found with that name. Press any key to continue");
		} break;
		case 'R': //Remove friend
		{
			Question("Enter username");
		} break;
	}

	int index = choice - '1';

	if (index >= 0 && index < player->GetFriends().length())
	{
		
	}
	return false;
}