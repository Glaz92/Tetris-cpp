#include "BlockFactory.h"



BlockFactory::BlockFactory()
{
}


BlockFactory::~BlockFactory()
{
}

std::shared_ptr<Block> BlockFactory::createBlock()
{
	return std::make_shared<BlockLong>();
}
