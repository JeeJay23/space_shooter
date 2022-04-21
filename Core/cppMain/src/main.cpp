/*
 * main.cpp
 *
 *  Created on: Mar 15, 2022
 *      Author: 31623
 */
#include <Protocol.h>
#include "main.h"
#include "GameEngine.h"
#include "Controller.h"


void cppMain(SPI_HandleTypeDef *hspi)
{
	Protocol protocol(hspi);
	Controller controllerA(0);
	Controller controllerB(1);
	GPU gpu(&protocol);
	GameEngine engine(&gpu);

	Player player(
			400,
			200,
			PLAYER_RADIUS,
			sprPlayer1,
			Vector(0,0),
			&controllerA,
			engine.toAdd,
			&engine.toAddCount,
			&engine
	);

	Player player2(
			600,
			400,
			PLAYER_RADIUS,
			sprPlayer2,
			Vector(0,0),
			&controllerB,
			engine.toAdd,
			&engine.toAddCount,
			&engine
	);

	engine.addPlayer(&player);
	engine.addPlayer(&player2);
	engine.controllerA = player.controller;
	engine.controllerB = player2.controller;

	for(;;){
		//engine.spiTrans();
		const int timeDelay = 20;

		// Read controller values.
		int starttick = HAL_GetTick();
		engine.loop();

//		protocol.drawSprite(400,400, 3);
//		protocol.drawSprite(200,400, 4);
//		protocol.drawSprite(400,100, 5);


		int stoptick = HAL_GetTick();

		if(stoptick-starttick > timeDelay)
			continue;

		HAL_Delay(timeDelay-(stoptick-starttick));

	}
}


