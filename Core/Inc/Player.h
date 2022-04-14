#pragma once
#include "gameObject.h"
#include "Controller.h"
#include "globals.h"
//#include <cmath>

class Player : public gameObject
{
private:
	double curFuel = PLAYER_MAXFUEL;

	int fireCooldown = 0;
	int bullets = 0;

	int isGrounded = 0;
	bool facingRight = true;

	Vector curVelocity;

	gameObject** toSpawn;
	int* toSpawnCnt;

	void spawnBullet(int, int, int);



public:
	Controller* controller;
	void move();

	Player(
			int x,
			int y,
			int radius,
			Vector spd,
			Controller* controller,
			gameObject** toSpawn,
			int* spawnCnt
			)
		: gameObject(x, y, radius)
		, controller(controller)
		, curVelocity(spd)
		, toSpawn(toSpawn)
		, toSpawnCnt(spawnCnt)
	{};

	Player()
		: gameObject(0, 0)
		, controller(nullptr)
		, curVelocity(Vector())
		, toSpawn(nullptr)
		, toSpawnCnt(nullptr)
	{};

	bool checkCollision(gameObject**, int);
	void onCollisionEnter(gameObject*);

};



