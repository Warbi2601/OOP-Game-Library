#pragma once

#include <string>
#include <iostream>
#include <typeinfo>
#include "Game.h"
#include "ListT.h"
#include "Account.h"

class Utils
{
  public:
    static std::string getLineFromUser();
	static char getCharFromUser();
	template <class T>
	static bool isType(T object, std::string type) 
	{
		return typeid(object).name() == type;
	}
	static bool StartsWith(const std::string&, const std::string&);
	static void ToUpper(std::string&);
	static void ToUpperRecursive(std::string&, int);
	static int getRandomNumber(int lower, int upper);
	static bool isUniqueUsername(List<Account*> accounts, std::string a);
};
