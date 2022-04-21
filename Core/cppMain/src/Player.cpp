#include "Player.h"
#include "Bullet.h"

void Player::spawnBullet(int x, int y, int speed)
{
	Bullet* toAdd = new Bullet(x, y, Vector(speed, -BULLET_INITIAL_UPWARDS_MOMENTUM), sprBullet);
	toSpawn[*toSpawnCnt] = toAdd; // array is checked every update. TODO move this logic to gameEngine
	(*toSpawnCnt)++;
}

int Player::map(int iEnd, int oEnd, int input)
{
	double slope = (double)(oEnd) / (double)(iEnd);
	return slope * (input);
}

void Player::move()
{
	// apply gravity
	if (!isGrounded)
		curVelocity.y += PLAYER_GRAVITY;

	// apply input logic
	if (controller->a) {
		if (curFuel > 0) {
			curVelocity.y += -PLAYER_MOVESPEED;
			curFuel -= PLAYER_FUELDRAIN;
		}

		isGrounded = 0;
	}
	if (controller->b) {
		curVelocity.y += PLAYER_MOVESPEED;
	}
	if (controller->left) {
		curVelocity.x += -PLAYER_MOVESPEED;
		facingRight = false;
	}
	if (controller->right) {
		curVelocity.x += PLAYER_MOVESPEED;
		facingRight = true;
	}

	// shoot bullet
	if (controller->a &&
		fireCooldown == 0 && 
		bullets < PLAYER_MAX_BULLETS) {

		const int offset = 20;

		fireCooldown = PLAYER_FIRE_COOLDOWN;
		long int sX = (facingRight) ? x + PLACEHOLDER_SPR_SIZE + offset : x - PLACEHOLDER_SPR_SIZE - offset;
		spawnBullet(sX, y, (facingRight) ? BULLET_SPEED : - BULLET_SPEED);
	}

	// if player is grounded, apply vertical drag
	if (isGrounded) {
		if (curVelocity.x > 0)
			curVelocity.x -= PLAYER_DRAG;
		else if (curVelocity.x < 0)
			curVelocity.x += PLAYER_DRAG;

		if (fabs(curVelocity.x) < PLAYER_MINSPEED) // deadzone
			curVelocity.x = 0;

		curFuel = PLAYER_MAXFUEL;
	}

	// clamp values to max movement speed
	curVelocity.x = fmin(PLAYER_MAXSPEED, fmax(curVelocity.x, -PLAYER_MAXSPEED));
	curVelocity.y = fmin(PLAYER_MAXSPEED, fmax(curVelocity.y, -PLAYER_MAXSPEED));

	// looping on screen edge
	if (x > SCREEN_WIDTH)
		x = 0;

	if (x < 0)
		x = SCREEN_WIDTH;

	int colIndex = map(SCREEN_WIDTH, groundColumnsAmount, x);

	// Ground
	if (y > SCREEN_HEIGHT - PLACEHOLDER_SPR_SIZE*2) {
		y = SCREEN_HEIGHT - PLACEHOLDER_SPR_SIZE*2;
		isGrounded = 1;
		curVelocity.y = 0; // cancel vertical velocity
	}

	// Ceiling
	if (y < PLACEHOLDER_SPR_SIZE) {
		isGrounded = 0;
		y = PLACEHOLDER_SPR_SIZE;
		curVelocity.y = 0; // cancel vertical velocity
	}

	// count down cooldown
	if (fireCooldown > 0) fireCooldown--;

	x += curVelocity.x;
	y += curVelocity.y;
}

bool Player::checkCollision(gameObject** others, int objCnt)
{
	// not used anymore
	return false;
}

void Player::onCollisionEnter(gameObject* other) 
{
	if (Bullet* bullet = dynamic_cast<Bullet*>(other))
		bullet->die();
}
