#include "LibraryItem.h"
#include "Date.h"

LibraryItem::LibraryItem(const Date& date, Game* game) : purchased(date), game(game)
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
