#pragma once
#include "BlockLong.h"
#include <memory>

class BlockFactory
{
public:
	BlockFactory();
	~BlockFactory();

public:
	static std::shared_ptr<Block> createBlock();

};

