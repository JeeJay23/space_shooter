/*
 * main.cpp
 *
 *  Created on: Mar 15, 2022
 *      Author: 31623
 */

#include <ADCController.h>
#include <Protocol.h>
#include "main.h"
#include "GameEngine.h"
#include "SPIController.h"


void cppMain(SPI_HandleTypeDef *hspi, ADC_HandleTypeDef *handle, uint32_t *buffer, SPI_HandleTypeDef *hspi2)
{
	Protocol protocol(hspi);
	ADCController controller(handle, buffer);
	SPIController spicontroller(hspi2);
	GPU gpu(&protocol);
	GameEngine engine(&gpu);

	Player player(gpu.width/2, gpu.height/2, Vector(0,0), &controller);
	Player player2(gpu.width/2, gpu.height/2, Vector(0,0), &spicontroller);
	engine.addPlayer(&player);
	engine.addPlayer(&player);
	engine.controllerA = player.controller;
	engine.controllerB = player2.controller;

	for(;;){
		//engine.spiTrans();

		// Read controller values.
		int starttick = HAL_GetTick();
		engine.loop();

//		if(controller.x < -160){
//			protocol.spriteX -= 1;
//			protocol.drawSprite(protocol.spriteX, protocol.spriteY);
//		}
//		else if(controller.y > 0){
//			protocol.spriteX += 1;
//			protocol.drawSprite(protocol.spriteX, protocol.spriteY);
//		}
//
////Check if out of bounds
//		if(protocol.spriteX < 144+16)
//			protocol.spriteX = 784-16;
//		else if(protocol.spriteX > 784-16)
//			protocol.spriteX = 144+16;
//
//		if(protocol.spriteY < 31+16)
//			protocol.spriteY = 511-16;
//		else if(protocol.spriteY > 511-16)
//			protocol.spriteY = 31+16;

		//protocol.drawSprite(protocol.spriteX, protocol.spriteY);
		//protocol.drawSprite(400, 400);

		int stoptick = HAL_GetTick();

		HAL_Delay(20-(stoptick-starttick));

	}
}


