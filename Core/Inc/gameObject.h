#pragma once
#include "Vector.h"
#include <string>

class gameObject
{
public:
	int x, y;
	int radius;
	gameObject() : x(0), y(0), radius(0) {};
	gameObject(int x, int y) : x(x), y(y), radius(0) {};
	gameObject(int x, int y, int rad) : x(x), y(y), radius(rad) {};
	virtual ~gameObject();

	virtual void move() = 0;
	virtual bool checkCollision(gameObject**, int) = 0;
	virtual void onCollisionEnter(gameObject*) = 0;
};

