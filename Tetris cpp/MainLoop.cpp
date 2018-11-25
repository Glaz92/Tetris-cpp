#include "MainLoop.h"

MainLoop * MainLoop::mainLoop = nullptr;

MainLoop::MainLoop()
{
}

MainLoop::~MainLoop()
{
}

MainLoop * MainLoop::get()
{
	if (mainLoop == nullptr)
		mainLoop = new MainLoop();

	return mainLoop;
}

void MainLoop::run()
{
	sf::Event event;

	while (WINDOW.isOpen())
	{
		while (WINDOW.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				WINDOW.close();
		}

		WINDOW.clear(sf::Color::Green);

		STATIC_ITEM.getGameState()->run();

		WINDOW.display();
	}
}
