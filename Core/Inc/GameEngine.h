/*
 * GameEngine.h
 *
 *  Created on: Mar 9, 2022
 *      Author: jvjad
 */

#ifndef GAMEENGINE_H_
#define GAMEENGINE_H_

#include "Controller.h"
#include "GPU.h"
#include "Map.h"
#include "gameObject.h"
#include "Player.h"

class GameEngine {
private:
	GPU *gpu;

	Map *map;
	int objCount = 0;
public:
	gameObject *objects[MAX_GAMEOBJ_COUNT];
	GameEngine(GPU *gpu);
	virtual ~GameEngine();
	void addPlayer(Player *player);
	void loop();
	void fixedUpdate();
	Controller *controllerA, *controllerB;
};

#endif /* GAMEENGINE_H_ */
