#include "Application.h"
#include "Admin.h"
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

Application::Application() : currentAccount(nullptr), currentUser(nullptr)
{
}

Application::~Application()
{
	for (int i = 0; i < 1; ++i)
	{
		delete accounts[i];
	}
}

bool Application::IsUserLoggedIn() const
{
	return currentUser != nullptr;
}

bool Application::IsAccountLoggedIn() const
{
	return currentAccount != nullptr;
}

Account* Application::GetCurrentAccount() const
{
	return currentAccount;
}

User* Application::GetCurrentUser() const
{
	return currentUser;
}

List<Account*> Application::GetAccounts() const
{
	return accounts;
}

void Application::AddAccount(Account* account) {
	accounts.addAtEnd(account);
}

Store& Application::GetStore()
{
	return store;
}

bool Application::LoginAccount(const std::string& email, const std::string& password)
{
	for (int i = 0; i < accounts.length(); i++) {
		Account* current = accounts[i];
	
		// An account with this email has been found
		if (current->GetEmail() == email) {
			// If the provided password matches the stored one,
			// set the current account and return successful
			if (current->GetPassword() == password) {
				currentAccount = current;
				return true;
			}
			break;
		}
	}
	// No account was found or invalid password
	return false;
}

bool Application::LoginUser(const std::string& username, const std::string& password)
{
	// Check if an account has been logged into
	if(currentAccount != nullptr) {
		// Loop over all the users in the current account
		for (int i = 0; i < currentAccount->GetUsers().length(); i++) {
			User* user = currentAccount->GetUsers()[i];

			if (user->GetUsername() == username) {
				// Username exists in current Account
				if (user->GetPassword() == password) {
					// Passwords match!
					currentUser = user;
					return true;
				}
			}
		}
	}

	// Invalid username or password
	return false;
}

void Application::LogoutUser()
{
	currentUser = nullptr;
}

void Application::Save() {

}

void Application::Load() {
	string line;
	Account* account = GetAccounts()[0];
	ifstream fin;
	fin.open("Data.txt", ios::in);
	if (fin.fail()) cout << "\nError loading data.";
	else {
		while (getline(fin, line)) {
			if (line == "GAME") {

				getline(fin, line);
				string name = line;

				getline(fin, line);
				string desc = line;

				getline(fin, line);
				int price = stoi(line);

				getline(fin, line);
				int age = stoi(line);

				GetStore().AddGame(new Game(name, desc, price, age));
			}

			else if (line == "ACCOUNT") {

				getline(fin, line);
				string email = line;

				getline(fin, line);
				string pass = line;

				getline(fin, line);
				string date = line;

				AddAccount(new Account(email, pass, date));

				if (line == "ACCOUNT-USER") {
					int i = 0;
					if (i == 0) {
						getline(fin, line);
						string name = line;

						getline(fin, line);
						string pass = line;

						getline(fin, line);
						string date = line;
						Player* u1 = new Admin(name, pass, date);

						account->AddUser(u1);
						i++;

						if (line == "ACCOUNT-USER-GAME") {
							getline(fin, line);
							string date = line;

							getline(fin, line);
							string game = line;

							getline(fin, line);
							int hours = stoi(line);

							//u1->AddToLibrary(new LibraryItem(date,game));
						}
					}

					else {
						getline(fin, line);
						string name = line;

						getline(fin, line);
						string pass = line;

						getline(fin, line);
						string date = line;
						Player* u1 = new Player(name, pass, date);

						account->AddUser(u1);
					}

				}
			}


		}
	}
}

void Application::LogoutAccount()
{
	currentAccount = nullptr;
}