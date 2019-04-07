#include "ProfileMenu.h"

ProfileMenu::ProfileMenu(const std::string& title, Application * app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void ProfileMenu::OutputOptions()
{
	Player* player = static_cast<Player*>(app->GetCurrentUser());

	Line("CREDITS: " + std::to_string(player->GetCredits()));
	Option('I', "Purchase 1 credit");
	Option('O', "Purchase 10 credit");
	Option('P', "Purchase 100 credit");

	Line("");  // newLine

	Line("Owned games:");
	//for loop which displays all games...
	for(int i = 0; i < player->GetLibrary().size(); i++)
	{
		LibraryItem* itm = player->GetLibrary()[i];
		string txt = itm->getGame()->GetName() + " (" + std::to_string(itm->getTimePlayed()) + ")";
		Option(i + 1,txt);
	}
	string boobies = typeid(player).name();
	// if the user is an admin display more options..
	if (typeid(player).name() == "Admin")
	{
		Line(""); // newLine

		Line("Admin:");
		Option('A', "Add new user");
		Option('R', "Remove user");
		Option('G', "Guest per-game access");
	}


}

bool ProfileMenu::HandleChoice(char choice)
{

	Player* player = static_cast<Player*>(app->GetCurrentUser());

	switch (choice)
	{
		//Add additional credits...
		case 'I': // 1 credits
		{
			player->AddCredits(1);
		} break;
		case 'O': // 10 credits
		{
			player->AddCredits(10);
		} break;
		case 'P': // 100 credits
		{
			player->AddCredits(100);
		} break;


		//edit user settings (All must ensure the user is an admin first...)s
		case 'A': //Add user
		{
			if (Utils::isType(app->GetCurrentUser(), "Admin"))
			{
				string username = Question("Enter a username");
				string password = Question("Enter a password");
				User* newUser = new User(username, password, Date::CurrentDate());
				app->GetCurrentAccount()->AddUser(newUser);
			}
		} break;
		case 'R': //Remove user
		{
			if (Utils::isType(app->GetCurrentUser(), "Admin"))
			{

			}
		} break;
		case 'G': //Guest per access game
		{
			if (Utils::isType(app->GetCurrentUser(), "Admin"))
			{

			}
		} break;

	}

	//Game add time random choice
	int index = choice - '1';

	if (index >= 0 && index < player->GetLibrary().size())
	{
		LibraryItem* selected = player->GetLibrary()[index];
		selected->IncrimentTimePlayed(Utils::getRandomNumber(10,100));
	}


	return false;
}