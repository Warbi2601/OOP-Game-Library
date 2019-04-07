#pragma once

#include "Account.h"
#include "User.h"
#include "Admin.h"
#include "Store.h"
#include "ListT.h"
#include "Utils.h"
#include "Admin.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>

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
		void Load();
		void Save();
		bool LoginAccount(const std::string& email, const std::string& password);
		void LogoutAccount();
		bool LoginUser(const std::string& username, const std::string& password);
		void LogoutUser();
		bool IsPlayer();
		bool IsAdmin();
private:
		Store store;
		Account* currentAccount;
		User* currentUser;
		List<Account*> accounts;
};
