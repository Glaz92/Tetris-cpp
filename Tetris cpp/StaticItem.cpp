#include "StaticItem.h"

StaticItem::StaticItem()
	: state(MAIN_MENU)
{
	font.loadFromFile("data/font/font.ttf");
	gameState.push_back(MainMenu::get());
}


StaticItem::~StaticItem()
{
	delete item;
}

StaticItem * StaticItem::get()
{
	if (item == nullptr)
		item = new StaticItem();

	return item;
}

GameState * StaticItem::getGameState()
{
	return gameState[state];
}
