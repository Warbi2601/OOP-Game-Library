#pragma once

#include <string>
#include <iostream>
#include "Game.h"
#include "ListT.h"

class Utils
{
  public:
    static std::string getLineFromUser();
    static char getCharFromUser();
	static bool StartsWith(const std::string&, const std::string&);
};

// TODO: 2 versions of ToUpper
