#include <iostream>
#include <string>
#include "Application.h"
#include "Account.h"
#include "User.h"
#include "Player.h"
#include "Admin.h"
#include "Utils.h"
#include "Date.h"

#include "MainMenu.h"

// TODO: Remove from global scope once menu system is integrated
Application app;

void main()
{
	// TODO: Remove call to dummy data, instead use Load and Save

	app.Load();
	MainMenu("VAPOUR", &app);
	// TODO: app.Save();
}
