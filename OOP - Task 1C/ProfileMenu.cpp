#include "ProfileMenu.h"

ProfileMenu::ProfileMenu(const std::string& title, Application * app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void ProfileMenu::OutputOptions()
{
	Line("CREDITS: ");
	Option('I', "Purchase 1 credit");
	Option('O', "Purchase 10 credit");
	Option('P', "Purchase 100 credit");

	Line("");  // newLine

	Line("Owned games:");
	//for loop which displays all games...


	// if the user is an admin display more options..
	//if(app->GetCurrentUser().)

	Line(""); // newLine

	Line("Games:");
	Option('A', "Add new user");
	Option('R', "Remove user");
	Option('G', "Guest per-game access");


}

bool ProfileMenu::HandleChoice(char choice)
{
	switch (choice)
	{
		//Add additional credits...
		case 'I': // 1 credits
		{
			
		} break;
		case 'O': // 10 credits
		{

		} break;
		case 'P': // 100 credits
		{

		} break;


		//edit user settings (All must ensure the user is an admin first...)s
		case 'A': //Add user
		{

		} break;
		case 'R': //Remove user
		{

		} break;
		case 'G': //Guest per access game
		{

		} break;

	}

	return false;
}