#pragma once
#include "Block.h"
class BlockL :
	public Block
{
private:
	int state;

public:
	BlockL();
	~BlockL();

public:
	virtual void rotate() override;
	virtual void derotate() override;
	virtual void setPosition(int x, int y) override;
};

