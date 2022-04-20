#include "Block.h"

void Block::move()
{
}

bool Block::checkCollision(gameObject** others, int objCnt)
{
	//TODO
	return false; 
}

void Block::onCollisionEnter(gameObject*)
{
}

std::string Block::getClassName()
{
	return "Block";
}
