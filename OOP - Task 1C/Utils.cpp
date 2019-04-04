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