#include "Map.h"

Map::Map()
{
	memset(&blocks, 0, sizeof(width * height));

	// initialize map
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {

			if (y == height-1 || y == 0) {
				blocks[x][y] = new Block(x * PLACEHOLDER_SPR_SIZE, y * PLACEHOLDER_SPR_SIZE);
			}
			else {
				blocks[x][y] = nullptr;
			}
		}
	}
}
