#include "Window.h"

Window * Window::window = nullptr;

Window::Window()
	: renderWindow(sf::VideoMode(800,600,32),"Tetris", sf::Style::Default)
{
}

Window::~Window()
{
	if (window != nullptr)
		delete window;
}

sf::RenderWindow * Window::get()
{
	if (window == nullptr)
	{
		window = new Window();
	}

	return &(window->renderWindow);
}

