#include "Player.h"
#include "Bullet.h"
#include "GameEngine.h"

void Player::spawnBullet(int x, int y, int speed) {
	Bullet *toAdd = new Bullet(x, y,
			Vector(speed, -BULLET_INITIAL_UPWARDS_MOMENTUM), sprBullet,
			&bullets);

	toSpawn[*toSpawnCnt] = toAdd; // array is checked every update. TODO move this logic to gameEngine
	(*toSpawnCnt)++;
	bullets++;
}

int Player::getColIndex(int input) {
	double slope = (double) (groundColumnsAmount) / (double) (SCREEN_WIDTH);
	return slope * input;
}

void Player::move() {
	if (controller == nullptr)
		return; // skip if player is unitialized

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

	if (controller->left) {
		curVelocity.x += -PLAYER_MOVESPEED;
		facingRight = false;
	}

	if (controller->right) {
		curVelocity.x += PLAYER_MOVESPEED;
		facingRight = true;
	}

	// shoot bullet
	if (controller->b && fireCooldown == 0 && bullets < PLAYER_MAX_BULLETS) {

		const int offset = 20;

		fireCooldown = PLAYER_FIRE_COOLDOWN;
		double sX =
				(facingRight) ?
						x + PLACEHOLDER_SPR_SIZE + offset :
						x - PLACEHOLDER_SPR_SIZE - offset;
		spawnBullet(sX, y, (facingRight) ? BULLET_SPEED : -BULLET_SPEED);
	}

	if (controller->start)
		engine->gpu->prot->drawMenu(0, 0);

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
	curVelocity.x = fmin(PLAYER_MAXSPEED,
			fmax(curVelocity.x, -PLAYER_MAXSPEED));
	curVelocity.y = fmin(PLAYER_MAXSPEED,
			fmax(curVelocity.y, -PLAYER_MAXSPEED));

	int colIndexLeft = getColIndex(x);
	int colIndexRight = getColIndex(x + PLACEHOLDER_SPR_SIZE);

	if (colIndexLeft < 0) {
		colIndexLeft = 0;
	}

	if (colIndexRight > groundColumnsAmount - 1) {
		colIndexRight = groundColumnsAmount - 1;
	}

	// evaluate groundedness
	isGrounded = !(y + PLACEHOLDER_SPR_SIZE < groundColumns[colIndexLeft]);

	// Ground collision
	if (y + PLACEHOLDER_SPR_SIZE > groundColumns[colIndexLeft]) {
		y = groundColumns[colIndexLeft] - PLACEHOLDER_SPR_SIZE;
		curVelocity.y = 0; // cancel vertical velocity
	} else if (y + PLACEHOLDER_SPR_SIZE > groundColumns[colIndexRight]) {
		y = groundColumns[colIndexRight] - PLACEHOLDER_SPR_SIZE;
		curVelocity.y = 0; // cancel vertical velocity
	}

	// Ceiling
	if (y < PLACEHOLDER_SPR_SIZE) {
		y = PLACEHOLDER_SPR_SIZE;
		curVelocity.y = 0; // cancel vertical velocity
	}

	// count down cooldown
	if (fireCooldown > 0)
		fireCooldown--;

	// calculate position after movement
	int nX = x + curVelocity.x;
	int nY = y + curVelocity.y;

	int nextColIndexLeft = getColIndex(nX);
	int nextColIndexRight = getColIndex(nX + PLACEHOLDER_SPR_SIZE);

	if (nX + PLACEHOLDER_SPR_SIZE > SCREEN_WIDTH) {
		nX = 0;
		nextColIndexRight = 0;
	}

	if (nX < 0) {
		nX = SCREEN_WIDTH - PLACEHOLDER_SPR_SIZE;
		nextColIndexLeft = groundColumnsAmount - 1;
	}

	// check if we will be in the wall
	if (nY > groundColumns[nextColIndexLeft]
			|| nY > groundColumns[nextColIndexRight]) {
		curVelocity.x = 0;
	} else {
		// only apply movement if we dont hit a wall
		x = nX;
		y = nY;
	}
}

bool Player::checkCollision(gameObject **others, int objCnt) {
	// not used anymore
	return false;
}

void Player::onCollisionEnter(gameObject *other) {
	if (Bullet *bullet = dynamic_cast<Bullet*>(other)) {
		bullet->die();
		if (type == sprPlayer1) {
			x = PLAYER1_RESPAWNX;
			y = PLAYER_RESPAWNY;
			points++;
		} else if (type == sprPlayer2) {
			x = PLAYER2_RESPAWNX;
			y = PLAYER_RESPAWNY;
			points++;
		}

		isGrounded = 0;
	}
}
