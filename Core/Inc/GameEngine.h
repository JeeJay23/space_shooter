/*
 * GameEngine.h
 *
 *  Created on: Mar 9, 2022
 *      Author: jvjad
 */

#ifndef GAMEENGINE_H_
#define GAMEENGINE_H_

#include "GPU.h"
#include "Controller.h"
#include "Map.h"
#include "gameObject.h"
#include "Player.h"

class GameEngine {
private:
	GPU *gpu;
	Controller *controllerA, *cntrlrB;
	Map *map;
	int objCount = 0;
public:
	gameObject *objects[MAX_GAMEOBJ_COUNT];
	GameEngine(Controller *controllerA, Controller *controllerB);
	virtual ~GameEngine();
	void addPlayer(Player *player);
	void loop();
	void fixedUpdate();
};

#endif /* GAMEENGINE_H_ */
