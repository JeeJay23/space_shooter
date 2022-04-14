#include "Player.h"
#include "Bullet.h"

void Player::spawnBullet(int x, int y, int speed)
{
	Bullet* toAdd = new Bullet(x, y, Vector(speed, -BULLET_INITIAL_UPWARDS_MOMENTUM));
	toSpawn[*toSpawnCnt] = toAdd; // array is checked every update. TODO move this logic to gameEngine
	(*toSpawnCnt)++;
}

void Player::move()
{
	// apply gravity
	if (!isGrounded)
		curVelocity.y += PLAYER_GRAVITY;

	// apply input logic
	if (controller->b) {
		if (curFuel > 0) {
			curVelocity.y += -PLAYER_MOVESPEED;
			curFuel -= PLAYER_FUELDRAIN;
		}

		isGrounded = 0;
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

		fireCooldown = PLAYER_FIRE_COOLDOWN;
		int sX = (facingRight) ? x + PLACEHOLDER_SPR_SIZE+8 : x - PLACEHOLDER_SPR_SIZE+8;
		spawnBullet(sX, y, (facingRight) ? BULLET_SPEED : - BULLET_SPEED);
	}

	// if player is grounded, apply vertical drag
	if (isGrounded) {
		if (curVelocity.x > 0)
			curVelocity.x -= PLAYER_DRAG;
		else if (curVelocity.x < 0)
			curVelocity.x += PLAYER_DRAG;

		if (abs(curVelocity.x) < PLAYER_MINSPEED) // deadzone
			curVelocity.x = 0;

		curFuel = PLAYER_MAXFUEL;
	}

	// clamp values to max movement speed
	curVelocity.x = fmin(PLAYER_MAXSPEED, fmax(curVelocity.x, -PLAYER_MAXSPEED));
	curVelocity.y = fmin(PLAYER_MAXSPEED, fmax(curVelocity.y, -PLAYER_MAXSPEED));

	// looping on screen edge
	if (x > SCREEN_WIDTH) {
		x = 0;
	}
	if (x < 0) {
		x = SCREEN_WIDTH;
	}
	if (y > SCREEN_HEIGHT - PLACEHOLDER_SPR_SIZE*2) {
		y = SCREEN_HEIGHT - PLACEHOLDER_SPR_SIZE*2;
		isGrounded = 1;
		curVelocity.y = 0; // cancel vertical velocity
	}
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
	for (int i = 0; i < objCnt; i++) {
		if (others[i] == this) continue;

		Vector player(x, y);
		if (player.distanceTo(others[i]->x, others[i]->y) <= radius) 
		{
			spawnBullet(this->x + 2, this->y - 50, BULLET_SPEED);
			return true;
		}
			
		return false;

	}
}

void Player::onCollisionEnter(gameObject* other) 
{
}
