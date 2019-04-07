#pragma once

#include "Game.h"
#include "Date.h"

class LibraryItem
{
	public:
		LibraryItem(const Date & date, Game * game, int time);
		~LibraryItem();

		const Game* getGame();
		const Date getDate();
		int getTimePlayed();
		void IncrementTimePlayed(int time);
	private:
		const Game* game;
		const Date purchased;
		int timePlayed;
};