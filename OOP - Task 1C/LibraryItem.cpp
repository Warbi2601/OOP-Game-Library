#include "LibraryItem.h"
#include "Date.h"

LibraryItem::LibraryItem(const Date& date, Game* game, int time) : purchased(date), game(game), timePlayed(time)
{
}

LibraryItem::~LibraryItem()
{
}

const Game* LibraryItem::getGame()
{
	return game;
}

const Date LibraryItem::getDate()
{
	return purchased;
}

int LibraryItem::getTimePlayed()
{
	return timePlayed;
}

void LibraryItem::IncrementTimePlayed(int time)
{
	timePlayed += time;
}
