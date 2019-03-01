#include "BlockFactory.h"

BlockFactory::BlockFactory()
{
}

BlockFactory::~BlockFactory()
{
}

std::shared_ptr<Block> BlockFactory::createBlock()
{
	switch (std::rand() % 3)
	{
	case 1:
		return std::make_shared<BlockS>();
	case 2:
		return std::make_shared<BlockSquare>();
	default:
		return std::make_shared<BlockLong>();
	}
}
