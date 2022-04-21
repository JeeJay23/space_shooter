#pragma once
#include "Protocol.h"
#include "gameObject.h"
#include "globals.h"

class GPU
{
private:


public:
	int width = SCREEN_WIDTH;
	int height = SCREEN_HEIGHT;

	Protocol *prot;

	GPU(Protocol *prot) : prot(prot) {}
	~GPU();
	void draw(gameObject**, int);
};

