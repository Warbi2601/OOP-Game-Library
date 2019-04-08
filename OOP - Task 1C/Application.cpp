#include "Application.h"

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
	assert(account != nullptr);

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
	ofstream fout;
	fout.open("copy.txt");
	for (int i = 0; i < GetStore().GetGames().length(); i++) {
		Game* game = GetStore().GetGames()[i];
		fout << "GAME" << endl;
		fout << game->GetID() << endl;
		fout << game->GetName() << endl;
		fout << game->GetDescription() << endl;
		fout << game->GetCost() << endl;
		fout << game->GetRating() << endl;
	}

	for (int i = 0; i < GetAccounts().length(); i++) {
		Account* account = GetAccounts()[i];
		fout << "ACCOUNT" << endl;
		fout << account->GetCreated().ToString(account->GetCreated()) << endl;
		fout << account->GetEmail() << endl;
		fout << account->GetPassword() << endl;
		for (int i = 0; i < account->GetUsers().length(); i++) {
			Player* user = static_cast<Player*>(account->GetUsers()[i]);
			fout << "ACCOUNT-USER" << endl;
			fout << user->GetCreated().ToString(user->GetCreated()) << endl;
			fout << user->GetUsername() << endl;
			fout << user->GetPassword() << endl;
			fout << user->GetCredits() << endl;

			for (int i = 0; i < user->GetLibrary().length(); i++) {
				LibraryItem* game = user->GetLibrary()[i];
				fout << "ACCOUNT-USER-GAME" << endl;
				fout << game->getGame()->GetID() << endl;
				fout << game->getDate().ToString(game->getDate()) << endl;
				fout << game->getTimePlayed() << endl;
			}
		}
	}
}

void Application::Load() {
	string line;
	ifstream fin;
	
	fin.open("data.txt", ios::in);
	if (fin.fail()) cout << "\nError loading data.";
	else {
		int count = 0;
		bool admin = true;
		User* u1;
		
		while (getline(fin, line)) {
			if (line == "GAME") {

				getline(fin, line);
				int id = stoi(line);

				getline(fin, line);
				string name = line;

				getline(fin, line);
				string desc = line;

				getline(fin, line);
				int price = stoi(line);

				getline(fin, line);
				int age = stoi(line);

				GetStore().AddGame(new Game(id, name, desc, price, age));
			}

			if (line == "ACCOUNT") {

				getline(fin, line);
				Date date = line;

				getline(fin, line);
				string email = line;

				getline(fin, line);
				string pass = line;

				AddAccount(new Account(email, pass, date));
				admin = true;
			}

			if (line == "ACCOUNT-USER") {
				
				if (admin) {

					getline(fin, line);
					Date date = line;

					getline(fin, line);
					string name = line;

					getline(fin, line);
					string pass = line;

					getline(fin, line);
					double credits = stod(line);

					u1 = new Admin(name, pass, date, credits);
					GetAccounts().last()->AddUser(u1);
					admin = false;
				}
				else {
					getline(fin, line);
					Date date = line;

					getline(fin, line);
					string name = line;

					getline(fin, line);
					string pass = line;

					getline(fin, line);
					double credits = stod(line);
					u1 = new Player(name, pass, date, credits);
					GetAccounts().last()->AddUser(u1);
				}
				
			}

			if (line == "ACCOUNT-USER-GAME") {
				List <Game*> games = store.GetGames();
				getline(fin, line);
				int game = stoi(line);

				getline(fin, line);
				Date date = line;

				getline(fin, line);
				int hours = stoi(line);

				u1 = GetAccounts().last()->GetUsers().last();
				Player* player = static_cast<Player*>(u1);
				player->AddToLibrary(new LibraryItem(date, games[game], hours));
				
			}
			
		}
	}
}

void Application::LogoutAccount()
{
	currentAccount = nullptr;
}

bool Application::IsPlayer() {
	if (IsUserLoggedIn())
	{
		if (Player *p = dynamic_cast<Player *>(GetCurrentUser())) {
			return true;
		}
	}
	return false;
}

bool Application::IsAdmin() {
	if (IsUserLoggedIn())
	{
		if (Admin *p = dynamic_cast<Admin *>(GetCurrentUser())) {
			return true;
		}
	}
	return false;
}