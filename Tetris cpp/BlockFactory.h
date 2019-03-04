#pragma once
#include "BlockLong.h"
#include "BlockS.h"
#include "BlockSquare.h"
#include "BlockZ.h"
#include "BlockL.h"
#include "BlockJ.h"
#include "BlockT.h"
#include <memory>

class BlockFactory
{
public:
	BlockFactory();
	~BlockFactory();

public:
	static std::shared_ptr<Block> createBlock();
};

