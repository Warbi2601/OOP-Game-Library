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
	app.AddAccount(new Account("alice@shu.ac.uk", "password", "2018-06-16"));

	Account* account = app.GetAccounts()[0];
	account->AddUser(u1);
	account->AddUser(u2);
	account->AddUser(u3);

}

void main()
{
	// TODO: Remove call to dummy data, instead use Load and Save
	createHardcodedTestData();

	// TODO: app.Load();
	MainMenu("VAPOUR", &app);
	// TODO: app.Save();
}
