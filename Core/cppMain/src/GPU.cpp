#include "GPU.h"

GPU::~GPU()
{
	delete(prot);
}

void GPU::draw(gameObject** obj, int objCount)
{
	// for every gameobject, send it's location to fpga
	for (int i = 0; i < objCount; i++){
		prot->drawSprite(obj[i]->x, obj[i]->y);
	}
}
