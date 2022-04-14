#pragma once
#include "Protocol.h"
#include "gameObject.h"
#include "globals.h"

class GPU
{
private:
	Protocol *prot;

public:
	int width = SCREEN_WIDTH;
	int height = SCREEN_HEIGHT;

	GPU(Protocol *prot) : prot(prot) {}
	~GPU();
	void draw(gameObject**, int);
};

