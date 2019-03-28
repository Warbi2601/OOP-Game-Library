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
		.AddGame(new Game("Final Fantasy", "Save the planet!", 1599, 5))
		.AddGame(new Game("Brothers", "Split your brain into two thumbs.", 799, 15));

	// Create some users
	Player* u1 = new Admin("Alice", "password", Date(16, 6, 2018));
	Player* u2 = new Player("Bob", "password", Date(19, 9, 2018));
	Player* u3 = new Player("Charlie", "password", Date(24, 9, 2018));

	// List of games
	List<Game*> games = app.GetStore().GetGames();

	// With some games in their library
	u1->AddToLibrary(new LibraryItem(Date(17, 6, 2018), games[0]))
		.AddToLibrary(new LibraryItem(Date(18, 6, 2018), games[1]));

	u2->AddToLibrary(new LibraryItem(Date(19, 9, 2018), games[2]))
		.AddToLibrary(new LibraryItem(Date(19, 9, 2018), games[3]));

	u3->AddToLibrary(new LibraryItem(Date(24, 9, 2018), games[3]))
		.AddToLibrary(new LibraryItem(Date(30, 9, 2018), games[6]));

	// Make an account and attach the users
	app.AddAccount(new Account("a", "a", Date(16, 6, 2018)));

	Account* account = app.GetAccounts()[0];
	account->AddUser(u1);
	account->AddUser(u2);
	account->AddUser(u3);

	// TODO: We need a login menu for accounts, for now we log in the only account
	app.LoginAccount("a", "a");
}


void main()
{
	// TODO: Remove call to dummy data, instead use Load and Save
	createHardcodedTestData();

	// TODO: app.Load();
	MainMenu("VAPOUR", &app);
	// TODO: app.Save();
}
