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
	static List<Game*> StartsWith();
};

// TODO: 2 versions of ToUpper
