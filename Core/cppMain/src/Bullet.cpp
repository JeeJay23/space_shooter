#include "Bullet.h"
#include "globals.h"
#include <iostream>

void Bullet::move()
{
	if (x > SCREEN_WIDTH)
		x = 0;

	if (x < 0)
		x = SCREEN_WIDTH;

	if (y > SCREEN_HEIGHT)
		die();

	if (y < 0)
		die();

	 curVelocity.y += BULLET_GRAVITY;

	x += curVelocity.x;
	y += curVelocity.y;
	
	ttl--;
	if (ttl == 0) {
		// kill yourself my man
		die();
	}
}

bool Bullet::checkCollision(gameObject** objs, int objCnt)
{
	//TODO
	return false;
}


void Bullet::die()
{
	curVelocity.x = 0;
	curVelocity.y = 0;
	x = -100;
}

void Bullet::onCollisionEnter(gameObject* other)
{
}
