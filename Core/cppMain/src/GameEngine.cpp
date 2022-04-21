#include "GameEngine.h"

GameEngine::GameEngine(GPU *gpu) :
		gpu(gpu) {
}

GameEngine::~GameEngine() {
	// TODO Auto-generated destructor stub
	delete (gpu);
	delete (controllerA);
	delete (controllerB);

	// TODO delete all objects
}

void GameEngine::addPlayer(Player *player) {
	objects[objCount] = player;
	objCount++;
}

void GameEngine::addObj(gameObject *toAdd) {
	if (objCount >= MAX_GAMEOBJ_COUNT - 1)
		return;

	objects[objCount] = toAdd;
	objCount++;
}

void GameEngine::loop() {
	// update inputs
	controllerA->update();
	controllerB->update();

	// run physics / game logic
	fixedUpdate();

	for (int i = 0; i < toAddCount; i++) {
		addObj(toAdd[i]);
	}

	toAddCount = 0;
	cleanup();
	// send to fpga
	gpu->draw(objects, objCount);
}

void GameEngine::fixedUpdate() {
	for (int i = 0; i < objCount; i++) {
		objects[i]->move();

		if (i == objCount - 1)
			break;

		for (int j = 0; j < objCount; j++) {
			/*if (objects[j]->getClassName() == "Block")
			 continue;*/
			if (i == j)
				continue;

			Vector pos(objects[i]->x, objects[i]->y);
			double distance = pos.distanceTo(objects[j]->x, objects[j]->y);
			//printf("%lf \n", distance);
			if (distance <= objects[i]->radius) {
				//TODO

				objects[i]->onCollisionEnter(objects[j]);
			}
		}
	}

	for (int i = 0; i < toAddCount; i++) {
		addObj(toAdd[i]);
	}

	toAddCount = 0;
}

void GameEngine::cleanup() {
	for (int i = 0; i < objCount; i++)
		if (objects[i]->x < -20 || objects[i]->x > SCREEN_WIDTH + 20)
			deleteAt(i);
}

void GameEngine::deleteAt(int toDelete) {
	delete (objects[toDelete]); // free memory
	objCount--;

	for (int i = toDelete; i < objCount; i++) {
		objects[i] = objects[i + 1]; // shift array to the left
	}
}
