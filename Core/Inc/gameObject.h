#pragma once
#include "Vector.h"
#include "globals.h"

class gameObject
{
public:
	int x, y;
	int radius;
	spriteType type;
	gameObject() : x(0), y(0), radius(0) {};
	gameObject(int x, int y) : x(x), y(y), radius(0) {};
	gameObject(int x, int y, int rad, spriteType type) : x(x), y(y), radius(rad), type(type) {};
	virtual ~gameObject();

	virtual void move() = 0;
	virtual bool checkCollision(gameObject**, int) = 0;
	virtual void onCollisionEnter(gameObject*) = 0;
};

