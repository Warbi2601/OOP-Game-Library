#pragma once

#include <string>
#include <iostream>
#include <typeinfo>
#include "Game.h"
#include "ListT.h"
#include "Account.cpp"

class Utils
{
  public:
    static std::string getLineFromUser();
	static char getCharFromUser();
	static bool StartsWith(const std::string&, const std::string&);
	static void ToUpper(std::string&);
	static void ToUpperRecursive(std::string&, int);
	static int getRandomNumber(int lower, int upper);
	//static bool isUniqueUsername(List<Account*> accounts, std::string a);
};
