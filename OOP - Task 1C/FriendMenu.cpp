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
			//string usernameSearch = Question("Enter username");
			//bool friendExists = player->AddFriend(app->GetAccounts(), usernameSearch);
			//
			//if (friendExists)
			//{
			//	Question("No user found with that name. Press any key to continue");
			//}
			//else
			//{
			//	Question("User added to your list of friends. Press any key to continue");

			//}
		} break;
		case 'R': //Remove friend
		{
			string usernameSearch = Question("Enter username");
			bool friendExists = player->RemoveFriend(usernameSearch);

			if (friendExists)
			{
				Question("User removed, you can add them again at any time. Press any key to continue");
			}
			else
			{
				Question("No user found with that name or you are already friends with that person. Press any key to continue");
			}
		} break;
	}

	if (!player->GetFriends().isEmpty())
	{
		int index = choice - '1';

		if (index >= 0 && index < player->GetFriends().length())
		{
			//Open a menu which allows you to choose a game to sell to selected player... (aka should pass the player*)

			//player->GetFriends()[index]
		}
	}
	return false;
}