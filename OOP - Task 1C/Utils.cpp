
#include "Utils.h"

std::string Utils::getLineFromUser()
{
    std::string input;
    std::getline(std::cin, input);
    return input;
}

char Utils::getCharFromUser()
{
    return toupper(getLineFromUser()[0]);
}

bool Utils::StartsWith(const std::string& searchString, const std::string& compareString)
{
	return compareString.compare(0, searchString.length(), searchString) == 0;
}

void Utils::ToUpper(std::string& stringToChange)
{
	for (int i = 0; i < stringToChange.length(); i++)
	{
		stringToChange[i] = toupper(stringToChange[i]);
	}
}

void Utils::ToUpperRecursive(std::string& stringToChange, int position)
{
	if (position < stringToChange.length())
	{
		stringToChange[position] = toupper(stringToChange[position]);
		position++;
		ToUpperRecursive(stringToChange, position);
	}
	else
	{
		return;
	}
}

int Utils::getRandomNumber(int lower, int upper)
{
	assert(lower < upper);
	return rand() % upper + lower;
}

bool Utils::isUniqueUsername(List<Account*> accounts, std::string a)
{
	Utils::ToUpper(a);

	for (int i = 0; i < accounts.length(); i++)
	{
		List<User*> users = accounts[i]->GetUsers();

		for (int x = 0; x < users.length(); x++)
		{
			string userUsername = users[x]->GetUsername();
			Utils::ToUpper(userUsername);

			if (userUsername == a)
			{
				return false;
			}
		}
	}
	return true;
}

Player* Utils::getPlayerByUsername(List<Account*> accounts, std::string username)
{
	Utils::ToUpper(username);

	for (int i = 0; i < accounts.length(); i++)
	{
		List<User*> users = accounts[i]->GetUsers();

		for (int x = 0; x < users.length(); x++)
		{
			string userUsername = users[x]->GetUsername();
			Utils::ToUpper(userUsername);

			if (userUsername == username)
			{
				return static_cast<Player*>(users[x]);;
			}
		}
	}
}
