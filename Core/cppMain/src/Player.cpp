#include "Player.h"

void Player::move()
{
	// apply gravity
	if (!isGrounded)
		curVelocity.y += gravity;

	// apply input logic
	if (controller->a) {
		if (curFuel > 0) {
			curVelocity.y += -mSpeed;
			curFuel -= fuelDrain;
		}

		isGrounded = 0;
	}
	if (controller->b) {
		curVelocity.y += mSpeed;
	}
	if (controller->left) {
		curVelocity.x += 100 * .5;
	}
	if (controller->right) {
		curVelocity.x += -100 * .5;
	}

	// if player is grounded, apply vertical drag
	if (isGrounded) {
		if (curVelocity.x > 0)
			curVelocity.x -= drag;
		else if (curVelocity.x < 0)
			curVelocity.x += drag;

		if (abs(curVelocity.x) < minSpeed) // deadzone
			curVelocity.x = 0;

		curFuel = maxFuel;
	}

	// clamp values to max movement speed
	curVelocity.x = fmin(maxSpeed, fmax(curVelocity.x, -maxSpeed));
	curVelocity.y = fmin(maxSpeed, fmax(curVelocity.y, -maxSpeed));

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

	x += curVelocity.x;
	y += curVelocity.y;
}

void Player::checkCollision(gameObject** others)
{
}
