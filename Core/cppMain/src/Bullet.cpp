#include "Bullet.h"
#include "globals.h"

int Bullet::getColIndex(int input)
{
	double slope = (double)(groundColumnsAmount) / (double)(SCREEN_WIDTH);
	return slope * input;
}

void Bullet::move()
{
	if(isDead)
		return;

	if (x + PLACEHOLDER_SPR_SIZE_HALF > SCREEN_WIDTH)
		x = PLACEHOLDER_SPR_SIZE_HALF;

	if (x - PLACEHOLDER_SPR_SIZE_HALF < 0)
		x = SCREEN_WIDTH - PLACEHOLDER_SPR_SIZE_HALF;

	if (y > SCREEN_HEIGHT)
		die();

	if (y < 0)
		die();

	 curVelocity.y += BULLET_GRAVITY;

	int colIndex = getColIndex(x+PLACEHOLDER_SPR_SIZE_HALF);

	if (colIndex > groundColumnsAmount - 1) {
		colIndex = groundColumnsAmount - 1;
	}

	if (colIndex < 0) {
		colIndex = 0;
	}

	if (y + PLACEHOLDER_SPR_SIZE > groundColumns[colIndex]){
		die();
	}

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
	(*playerBulletCount)--;
	isDead = true;
}

void Bullet::onCollisionEnter(gameObject* other)
{

}
