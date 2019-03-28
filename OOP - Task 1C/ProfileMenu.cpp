#include "ProfileMenu.h"

ProfileMenu::ProfileMenu(const std::string& title, Application * app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void ProfileMenu::OutputOptions()
{
	Line("CREDITS: ");
	Option('S', "Browse Store");


}

bool ProfileMenu::HandleChoice(char choice)
{
	switch (choice)
	{
		case 'S':
		{
			
		} break;
	}

	return false;
}