#include "Application.h"
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

Store& Application::GetStore()
{
	return store;
}

bool Application::LoginAccount(const std::string& email, const std::string& password)
{
	// TODO: This currently always logs you in as the first account
	currentAccount = accounts[0];

	return true;
}

bool Application::LoginUser(const std::string& username, const std::string& password)
{
	// TODO: This currently always logs you in as the first user
	currentUser = currentAccount->users[0];

	return true;
}

void Application::LogoutUser()
{
	currentUser = nullptr;
}

void Application::Save() {
	
}

void Application::Load() {
	string line;
	ifstream fin;
	fin.open("Data.txt", ios::in);
	if (fin.fail()) cout << "\nError loading data.";
	else {
		while (getline(fin, line)) {
			if (line == "GAME"){
				app.GetStore().games[0] = new Game("The Witness", "Explore a nice island and solve puzzles.", 2999, 5);
			}

		}
		

}