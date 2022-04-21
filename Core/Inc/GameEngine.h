
#ifndef GAMEENGINE_H_
#define GAMEENGINE_H_

#include "GPU.h"
#include "Controller.h"
#include "Player.h"
#include "globals.h"

class GameEngine
{
private:
public:
	GameEngine(GPU *gpu);

	GPU *gpu;
	virtual ~GameEngine();

	gameObject *objects[MAX_GAMEOBJ_COUNT];
	int objCount = 0;
	gameObject *toAdd[MAX_TOADD_COUNT];
	int toAddCount = 0;

	Controller *controllerA, *controllerB;

	void addPlayer(Player *player);
	void addObj(gameObject* toAdd);
	void loop();
	void fixedUpdate();
	void cleanup();
	void deleteAt(int);
};

#endif /* GAMEENGINE_H_ */


