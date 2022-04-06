/*
 * main.cpp
 *
 *  Created on: Mar 15, 2022
 *      Author: 31623
 */

#include <protocol.h>
#include "main.h"
#include "ControllerInput.h"

void cppMain(SPI_HandleTypeDef *hspi, ADC_HandleTypeDef *handle)
{
	protocol protocol(hspi);
	ControllerInput controller(handle);


	for(;;){
		//engine.spiTrans();

		// Read controller values.
		int starttick = HAL_GetTick();

		controller.getControllerState();


		if(controller.joyStickX < -160){
			protocol.spriteX -= 1;
			protocol.drawSprite(protocol.spriteX, protocol.spriteY);
		}
		else if(controller.joyStickX > 0){
			protocol.spriteX += 1;
			protocol.drawSprite(protocol.spriteX, protocol.spriteY);
		}

//Check if out of bounds
		if(protocol.spriteX < 144+16)
			protocol.spriteX = 784-16;
		else if(protocol.spriteX > 784-16)
			protocol.spriteX = 144+16;

		if(protocol.spriteY < 31+16)
			protocol.spriteY = 511-16;
		else if(protocol.spriteY > 511-16)
			protocol.spriteY = 31+16;

		//protocol.drawSprite(protocol.spriteX, protocol.spriteY);
		//protocol.drawSprite(400, 400);

		int stoptick = HAL_GetTick();

		HAL_Delay(20-(stoptick-starttick));

	}
}


