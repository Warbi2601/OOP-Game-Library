#pragma once

#include "Account.h"
#include "User.h"
#include "Store.h"
#include "ListT.h"

class Application
{
	public:
		Application();
		~Application();

		bool IsAccountLoggedIn() const;
		bool IsUserLoggedIn() const;
		Account* GetCurrentAccount() const;
		User* GetCurrentUser() const;
		List<Account*> GetAccounts() const;
		void AddAccount(Account * account);

		Store& GetStore();

		bool LoginAccount(const std::string& email, const std::string& password);
		bool LoginUser(const std::string& username, const std::string& password);
		void LogoutUser();
	private:
		Store store;
		Account* currentAccount;
		User* currentUser;
		List<Account*> accounts;
};