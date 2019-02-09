#include "MainLoop.h"

MainLoop::MainLoop()
{
}

MainLoop::~MainLoop()
{
}

MainLoop & MainLoop::get()
{
	static MainLoop mainLoop;

	return mainLoop;
}

void MainLoop::run()
{
	sf::Event event;

	while (GetWindow().isOpen())
	{
		while (GetWindow().pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				GetWindow().close();
		}

		GetWindow().clear(sf::Color::Green);

		GetStaticItem().getGameState()->run();

		GetWindow().display();
	}
}