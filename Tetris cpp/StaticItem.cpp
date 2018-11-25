#include "StaticItem.h"

StaticItem * StaticItem::item = nullptr;

StaticItem::StaticItem()
	: state(State::MainMenu)
{
	gameState.emplace(std::make_pair(State::MainMenu,MainMenu::get()));
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
