#include "LibraryItem.h"
#include "Date.h"

LibraryItem::LibraryItem(const Date& date, Game* game) : purchased(date), game(game)
{
}

LibraryItem::~LibraryItem()
{
}