#include "Window.h"

Window * Window::window = nullptr;

Window::Window()
{
}

Window::~Window()
{
	if (window != nullptr)
		delete window;
}

Window * Window::get()
{
	if (window == nullptr)
	{
		window = new Window();
	}

	return window;
}

