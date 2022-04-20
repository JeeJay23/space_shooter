#include "GPU.h"
#include "globals.h"

GPU::~GPU()
{
	delete(prot);
}

void GPU::draw(gameObject** obj, int objCount)
{
	int bulletAddr = 3;
	// for every gameobject, send it's location to fpga
	for (int i = 0; i < objCount; i++){
		switch(obj[i]->type)
		{
		case sprPlayer1 :
			prot->drawSprite(obj[i]->x, obj[i]->y, 1);
			break;
		case sprPlayer2 :
			prot->drawSprite(obj[i]->x, obj[i]->y, 2);
			break;
		case sprBullet :
			prot->drawSprite(obj[i]->x, obj[i]->y, bulletAddr);
			bulletAddr++;
			break;

		}
	}
	for(int j = bulletAddr; j <= PLAYER_MAX_BULLETS*2+2; j++)
	{
		prot->drawSprite(-100, -100, j);
	}
}
