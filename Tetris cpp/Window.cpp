#include "Window.h"

Window::Window()
	: renderWindow(sf::VideoMode(370,400,32),"Tetris", sf::Style::Default)
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