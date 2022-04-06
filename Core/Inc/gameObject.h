#pragma once
#include "Vector.h"

class gameObject
{
public:
	int x, y;
	gameObject() : x(0), y(0) {};
	gameObject(int x, int y) : x(x), y(y) {};
	virtual ~gameObject();

	virtual void move() = 0;
	virtual void checkCollision(gameObject**) = 0;
};

