#pragma once
#include "gameObject.h"

class Block : public gameObject
{
public:
	void move();
	Block(int x, int y) : gameObject(x, y) {};
	bool checkCollision(gameObject**, int);
	void onCollisionEnter(gameObject*);
	std::string getClassName();
};

