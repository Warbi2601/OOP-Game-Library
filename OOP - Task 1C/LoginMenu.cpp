#include "LoginMenu.h"

using namespace std;

LoginMenu::LoginMenu(const std::string& title, Application * app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void LoginMenu::OutputOptions()
{
	for (int i = 0; i < 3; i++) //app->GetCurrentAccount()->users)
	{
		Option(i, app->GetCurrentAccount()->GetUsers()[i]->GetUsername());
	}
}

bool LoginMenu::HandleChoice(char choice)
{
	switch (choice)
	{
		case 'L':
		{
			if (app->IsUserLoggedIn())
			{
				std::string answer = Question("Are you sure?");
				if (answer == "y" || answer == "Y")
				{
					//app->LogOut();
				}
			}
			else
			{
				// this would need to go to a LoginMenu - similar to StoreMenu
				// instead we just set logged in to true on the main app object

				//app->LogIn();
			}
		} break;
		case 'P':
		{
			if (app->IsUserLoggedIn())
			{
				Question("Not implemented, press return to continue (");
				// this needs to go to a profile page - similar to StoreMenu
				// notice the if - this only works if somebody is logged in
			}
		} break;
	}

	return false;
}