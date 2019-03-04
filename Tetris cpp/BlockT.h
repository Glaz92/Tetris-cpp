#pragma once
#include "Block.h"
class BlockT :
	public Block
{
private:
	int state;

public:
	BlockT();
	~BlockT();

public:
	virtual void rotate() override;
	virtual void derotate() override;
	virtual void setPosition(int x, int y) override;
};

