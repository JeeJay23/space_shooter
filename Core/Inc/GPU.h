#pragma once
#include "Frame.h"
#include "gameObject.h"
#include "globals.h"
#include "Map.h"

class GPU
{
public:
	int width = SCREEN_WIDTH;
	int height = SCREEN_HEIGHT;

	GPU();
	~GPU();
	void draw(gameObject**, int);
};

