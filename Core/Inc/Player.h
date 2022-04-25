#pragma once
#include "gameObject.h"
#include "Controller.h"
#include "globals.h"
#include "protocol.h"
#include <cmath>

class GameEngine;

class Player : public gameObject
{
private:
	double curFuel = PLAYER_MAXFUEL;

	GameEngine *engine;

	int fireCooldown = 0;
	int bullets = 0;
	int isGrounded = 0;
	bool facingRight = true;

	Vector curVelocity;
	gameObject** toSpawn;
	int* toSpawnCnt;

	void spawnBullet(int, int, int);
	int getColIndex(int);

public:

	Controller* controller;
	int points = 0;
	void move();

	Player(
			int x,
			int y,
			int radius,
			spriteType type,
			Vector spd,
			Controller* controller,
			gameObject** toSpawn,
			int* spawnCnt,
			GameEngine *engine
			)
		: gameObject(x, y, radius, type)
		, controller(controller)
		, curVelocity(spd)
		, toSpawn(toSpawn)
		, toSpawnCnt(spawnCnt)
		, engine(engine)
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



