#include "ConstElements.h"

ConstElements::ConstElements()
{
	font.loadFromFile("data/font/font.ttf");
}


ConstElements::~ConstElements()
{
}

ConstElements & ConstElements::get()
{
	static ConstElements constElements;

	return constElements;
}
