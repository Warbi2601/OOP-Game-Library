#pragma once

#include <string>
#include <iostream>
#include <typeinfo>

class Utils
{
  public:
    static std::string getLineFromUser();
	static char getCharFromUser();
	template <class T>
	static bool isType(T object, std::string type) {
		return typeid(object).name() == type;
	}
};

// TODO: 2 versions of ToUpper
