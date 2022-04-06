/*
 * GameEngine.cpp
 *
 *  Created on: Mar 9, 2022
 *      Author: jvjad
 */

#include "GameEngine.h"

GameEngine::GameEngine(Controller *controllerA, Controller *controllerB) : controllerA(controllerA) {
	// TODO Auto-generated constructor stub
	gpu = new GPU();

	memset(objects, 0, MAX_GAMEOBJ_COUNT*sizeof(gameObject*));

}

GameEngine::~GameEngine() {
	// TODO Auto-generated destructor stub
	delete(gpu);
	delete(controllerA);

	// TODO delete all objects
}

void GameEngine::addPlayer(Player *player) {
	objects[objCount] = player;
	objCount++;
}

void GameEngine::loop()
{
	// update inputs
	controllerA->update();

	// run physics / game logic
	fixedUpdate();

	// send to fpga
	gpu->draw(objects, objCount);

}

void GameEngine::fixedUpdate() {
	for (int i = 0; i < objCount; i++){
		objects[i]->move();
	}
}
