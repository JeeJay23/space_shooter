#pragma once
#include "Controller.h"
#include "gameObject.h"
#include "globals.h"
#include <cmath>

class Player : public gameObject
{
private:
	// general
	const double mSpeed = 1.5;
	const double minSpeed = .5f;
	const double maxSpeed = 10;
	const double gravity = 1;
	const double drag = 0.8;

	// jetpack
	const double maxFuel = 100;
	const double fuelDrain = .5f;

	double curFuel = maxFuel;
	int isGrounded = 0;

	Vector curVelocity;

public:
	void move();

	Player(int x, int y, Vector spd, Controller* controller)
		: gameObject(x, y)
		, controller(controller)
		, curVelocity(spd) {};

	Player() : gameObject(0, 0), controller(nullptr), curVelocity(Vector()) {};
	void checkCollision(gameObject**);
	Controller* controller;
};

