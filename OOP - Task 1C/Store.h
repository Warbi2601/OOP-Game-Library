#pragma once

#include "Game.h"
#include "ListT.h"

class Store
{
	public:
		Store();
		~Store();

		List<Game*> GetGames() const;
		Store& AddGame(Game* game);
		// void RemoveGame(string name);
	private:
		List<Game*> games;
};