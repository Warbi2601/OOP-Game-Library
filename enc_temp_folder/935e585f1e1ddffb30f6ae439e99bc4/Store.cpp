#include "Store.h"

Store::Store()
{
}

Store::~Store()
{
	for (int i = 0; i < 9; ++i)
	{
		delete games[i];
	}
}

List<Game*> Store::GetGames() const
{
	return games;
}

Store& Store::AddGame(Game* game) {
	games.addAtEnd(game);
	return *this;
}
