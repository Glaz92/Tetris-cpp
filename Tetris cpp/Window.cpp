#include "Window.h"

Window::Window()
	: renderWindow(sf::VideoMode(800,600,32),"Tetris", sf::Style::Default)
{
}

Window::~Window()
{
}

sf::RenderWindow & Window::get()
{
	static Window window;

	return window.renderWindow;
}