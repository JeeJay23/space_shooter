#pragma once
#include "gameObject.h"

class Block : public gameObject
{
public:
	void move();
	Block(int x, int y) : gameObject(x, y) {};
	void checkCollision(gameObject**);
};

