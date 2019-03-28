#include "MainMenu.h"

MainMenu::MainMenu(const std::string& title, Application * app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void MainMenu::OutputOptions()
{
	Option('S', "Browse Store");

	if (app->IsUserLoggedIn())
	{
		Option('P', "View Profile");
		Option('L', "Logout of user");
	}
	else
	{
		if (app->IsAccountLoggedIn())
		{
			Option('L', "Login to user");
			Option('Q', "Logout of account");
		}
		else
		{
			Option('L', "Login to account");
		}
	}
}

bool MainMenu::HandleChoice(char choice)
{
	switch (choice)
	{
		case 'S':
		{
			StoreMenu("STORE", app);
		} break;
		case 'L':
		{
			if (app->IsAccountLoggedIn())
			{
				if (app->IsUserLoggedIn())
				{
					std::string answer = Question("Are you sure?");
					if (answer == "y" || answer == "Y") app->LogoutUser();
				}
				else LoginMenu("Login", app);
			}
			else
			{
				string email = Question("Enter your account email: ");
				string password = Question("Enter your account password: ");
				if (!app->LoginAccount(email, password)) Line("Login failed, try again...");

			}
		} break;
		case 'Q':
		{
			std::string answer = Question("Are you sure?");
			if (answer == "y" || answer == "Y") app->LogoutAccount();
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