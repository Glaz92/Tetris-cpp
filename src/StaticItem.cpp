#include "StaticItem.h"
#include <iostream>

StaticItem::StaticItem()
	: state(State::MainMenu)
{
	gameState.emplace(std::make_pair(State::MainMenu, std::make_shared<MainMenu>()));
	gameState.emplace(std::make_pair(State::Game, std::make_shared<Game>()));
}


StaticItem::~StaticItem()
{
}

StaticItem & StaticItem::get()
{
	static StaticItem item;

	return item;
}

std::shared_ptr<GameState> StaticItem::getGameState()
{
	return gameState[state];
}
