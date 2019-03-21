#include <iostream>
#include <string>
#include "Application.h"
#include "Account.h"
#include "User.h"
#include "Player.h"
#include "Admin.h"
#include "Utils.h"
#include "Date.h"

// TODO: Remove from global scope once menu system is integrated
Application app;

void createHardcodedTestData()
{
	// Setup store with some games
	app.GetStore().AddGame(new Game("The Witness", "Explore a nice island and solve puzzles.", 2999, 5))
		.AddGame(new Game("Braid", "A time twisting puzzle game.", 499, 15))
		.AddGame(new Game("Factorio", "Build a complicated factory in space.", 1599, 12))
		.AddGame(new Game("LIMBO", "Watch out for that spider.", 299, 12))
		.AddGame(new Game("INSIDE", "What are those scientists even doing?!", 1299, 15))
		.AddGame(new Game("Portal 2", "Play around with physics. Shoot the moon.", 1999, 15))
		.AddGame(new Game("Half Life 3", "It's never coming out.", 5999, 18))
		.AddGame(new Game("Castle Crashers", "A small giraffe follows you around.", 999, 18))
		.AddGame(new Game("Brothers", "Split your brain into two thumbs.", 799, 15));

	// Create some users
	Player* u1 = new Admin("Alice", "password", "2018-06-16");
	Player* u2 = new Player("Bob", "password", "2018-09-19");
	Player* u3 = new Player("Charlie", "password", "2018-09-24");


	// List of games
	List<Game*> games = app.GetStore().GetGames();

	// With some games in their library
	u1->AddToLibrary(new LibraryItem("2018-06-17", games[0]))
		.AddToLibrary(new LibraryItem("2018-06-18", games[1]));

	u2->AddToLibrary(new LibraryItem("2018-09-19", games[2]))
		.AddToLibrary(new LibraryItem("2018-09-19", games[3]));

	u3->AddToLibrary(new LibraryItem("2018-09-24", games[3]))
		.AddToLibrary(new LibraryItem("2018-09-30", games[6]));

	// Make an account and attach the users
	app.AddAccount(new Account("alice@shu.com", "password", "2018-06-16"));
	
	Account* account = app.GetAccounts()[0];
	account->AddUser(u1);
	account->AddUser(u2);
	account->AddUser(u3);

	// TODO: We need a login menu for accounts, for now we log in the only account
	app.LoginAccount("alice@shu.ac.uk", "password");
}

char showMainMenuAndGetUserChoice()
{
	system("CLS");

	////TEST
	//Date date(1, 4, 1996);

	//date.setMonth(2);
	//date.setDay(30);
	//date.setYear(2010);
	//std::cout << &date;

	std::cout << '\n';
	std::cout << &Date::CurrentDate();
	std::cout << "                    \n";
	std::cout << "  -= GAME LIBRARY =-\n";
	std::cout << "                    \n";
	std::cout << "  S) Browse Store   \n";

	if (app.IsUserLoggedIn())
	{
		std::cout << "  L) Logout of " << app.GetCurrentUser()->GetUsername() << "\n";
		// TODO: User profile option
	}
	else
	{
		std::cout << "  L) Login      \n";
	}

	std::cout << "                    \n";
	std::cout << "  B) Exit           \n";
	std::cout << "                    \n";
	std::cout << "                    \n";
	std::cout << "  >>> ";

	return Utils::getCharFromUser();
}

char showStoreMenuAndGetUserChoice()
{
	system("CLS");
	std::cout << "                    \n";
	std::cout << "  -= STORE =-       \n";
	std::cout << "                    \n";

	Store& store = app.GetStore();
	for (int i = 0; i < store.GetGames().length(); i++) {
		std::cout << "  " << (i + 1) << ") " << store.GetGames()[i]->GetName() << "\n";
	}

	// TODO: Implement search store option

	// Output rest of menu
	std::cout << "                    \n";
	std::cout << "  B) Back           \n";
	std::cout << "                    \n";
	std::cout << "                    \n";
	std::cout << "  >>> ";

	return Utils::getCharFromUser();
}

char showLoginUserMenuAndGetUserChoice(Account *account)
{
	system("CLS");
	std::cout << "                    \n";
	std::cout << "  -= LOGIN =-       \n";
	std::cout << "                    \n";

	// Output user list
	Store& store = app.GetStore();
	for (int i = 0; i < account->GetUsers().length(); i++) {
		std::cout << "  " << (i + 1) << ") " << account->GetUsers()[i]->GetUsername() << "\n";
	}


	// Output rest of menu
	std::cout << "                    \n";
	std::cout << "  B) Back           \n";
	std::cout << "                    \n";
	std::cout << "                    \n";
	std::cout << "  >>> ";

	return Utils::getCharFromUser();
}

char showGameMenuAndGetUserChoice(Game* game)
{
	system("CLS");
	std::cout << "                                  \n";
	std::cout << "  -= " << game->GetName() << " =- \n";
	std::cout << "                                  \n";
	std::cout << "  " << game->GetDescription() << "\n";
	std::cout << "                                  \n";

	if (app.IsUserLoggedIn())
	{
		std::cout << "  P) Purchase for " << (game->GetCost() / 100.0f) << "\n";
		std::cout << "                                                      \n";
	}

	std::cout << "  B) Back                   \n";
	std::cout << "                            \n";
	std::cout << "                            \n";
	std::cout << "  >>> ";

	return Utils::getCharFromUser();
}

void gameMenu(Game* game)
{
	bool readyToGoBack = false;

	while (readyToGoBack == false)
	{
		int choice = showGameMenuAndGetUserChoice(game);

		switch (choice)
		{
			case 'P': {
				if (app.IsUserLoggedIn())
				{
					// TODO: Implement buying from the store
				}
			} break;
			case 'B': {
				readyToGoBack = true;
			} break;
		}
	}
}

void storeMenu()
{
	bool readyToGoBack = false;

	while (readyToGoBack == false)
	{
		int choice = showStoreMenuAndGetUserChoice();

		switch (choice)
		{
			case 'B': {
				readyToGoBack = true;
			} break;
			default: {
				int index = choice - '1';

				if (index >= 0 && index < app.GetStore().GetGames().length()) {
					gameMenu(app.GetStore().GetGames()[index]);
				}
			} break;
		}
	}
}

void loginUserMenu()
{
	bool readyToGoBack = false;

	while (readyToGoBack == false)
	{
		int choice = showLoginUserMenuAndGetUserChoice(app.GetCurrentAccount());

		switch (choice)
		{
			case 'B': {
				readyToGoBack = true;
			} break;
			default: {
				int index = choice - '1';

				if (index >= 0 && index < app.GetCurrentAccount()->GetUsers().length()) // TODO: Hardcoded, change when using List<T>
				{
					std::string username = app.GetCurrentAccount()->GetUsers()[index]->GetUsername();

					std::cout << "  Enter password for " << username << ": ";
					if (app.LoginUser(username, Utils::getLineFromUser()))
					{
						readyToGoBack = true;
					}
				}
			} break;
		}
	}
}

void mainMenu()
{
	bool wantsToExit = false;

	while (wantsToExit == false)
	{
		int choice = showMainMenuAndGetUserChoice();

		switch (choice)
		{
			case 'S': {
				storeMenu();
			} break;
			case 'L': {
				if (app.IsUserLoggedIn())
				{
					app.LogoutUser();
				}
				else
				{
					loginUserMenu();
				}
			} break;
			case 'B': {
				wantsToExit = true;
			} break;
		}
	}
}

void main()
{
	// TODO: Remove call to dummy data, instead use Load and Save
	createHardcodedTestData();

	// TODO: app.Load();
	mainMenu();
	// TODO: app.Save();
}