#include "Application.h"

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