#pragma once
#include "Block.h"
class BlockJ :
	public Block
{
private:
	int state;

public:
	BlockJ();
	~BlockJ();

public:
	virtual void rotate() override;
	virtual void derotate() override;
	virtual void setPosition(int x, int y) override;
};

