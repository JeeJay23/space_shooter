#pragma once
#include "globals.h"
#include "Block.h"
#include <cstring>

class Map
{
public:
	const static int tileSize = PLACEHOLDER_SPR_SIZE;
	const static int width = SCREEN_WIDTH / tileSize;
	const static int height = SCREEN_HEIGHT / tileSize;

	gameObject* blocks[width][height];

	Map();
	~Map() {};
};

