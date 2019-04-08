#include "GiftFriendMenu.h"

GiftFriendMenu::GiftFriendMenu(const std::string & title, Application * app, Player * sendingTo) : Menu(title, app), sendingTo(sendingTo)
{
	Paint(); // required in constructor
}

void GiftFriendMenu::OutputOptions()
{
	Player* player = static_cast<Player*>(app->GetCurrentUser());
	Line("Select a game to sell to " + sendingTo->GetUsername());
	Line("Selling a game to a friend will only charge them 50% of the original cost.");

	for(int i = 0; i < player->GetLibrary().size(); i++)
	{
		const Game* game = player->GetLibrary()[i]->getGame();
		Option(i + 1, game->GetName());
	}
}

bool GiftFriendMenu::HandleChoice(char choice)
{
	Player* player = static_cast<Player*>(app->GetCurrentUser());

	if (!player->GetFriends().isEmpty())
	{
		int index = choice - '1';

		if (index >= 0 && index < player->GetLibrary().size())
		{
			LibraryItem* libItem = player->GetLibrary()[index];
			player->SellGameToFriend(sendingTo, libItem);
		}
	}
	return false;
}