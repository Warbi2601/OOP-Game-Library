#pragma once

#include "Game.h"
#include "Date.h"

class LibraryItem
{
	public:
		LibraryItem(const Date&, Game*);
		~LibraryItem();

		const Game* getGame();
		const Date getDate();
		int getTimePlayed();
	private:
		const Game* game;
		const Date purchased;
		int timePlayed;
};