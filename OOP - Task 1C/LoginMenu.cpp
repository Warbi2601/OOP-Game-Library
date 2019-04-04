#include "LoginMenu.h"

using namespace std;

LoginMenu::LoginMenu(const std::string& title, Application * app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void LoginMenu::OutputOptions()
{
	for (int i = 0; i < app->GetCurrentAccount()->GetUsers().length(); i++)
	{
		Option(i, app->GetCurrentAccount()->GetUsers()[i]->GetUsername());
	}
}

bool LoginMenu::HandleChoice(char choice)
{

	int choiceAsInt = choice - '0';
	if (choiceAsInt <= app->GetCurrentAccount()->GetUsers().length() || choiceAsInt >= 0)
	{
		string username = app->GetCurrentAccount()->GetUsers()[choiceAsInt]->GetUsername();
		string password = Question("Enter your password:");

		app->LoginUser(username, password);
		return true;

	}
	

	return false;
}