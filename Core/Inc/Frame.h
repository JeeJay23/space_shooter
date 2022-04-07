#pragma once
#include "Line.h"
#include "Sprite.h"

class Frame
{
public:
	Line lines[100];
	Sprite sprites[100];
	int lineCount = 0;
	int spriteCount = 0;
};

