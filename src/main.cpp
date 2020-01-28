#include "MainLoop.h"

int main()
{
	std::srand(std::time(NULL));
	MainLoop::get().run();
	return 0;
}