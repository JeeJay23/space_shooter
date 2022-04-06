/*
 * main.cpp
 *
 *  Created on: Mar 15, 2022
 *      Author: 31623
 */

#include <Controller.h>
#include <protocol.h>
#include "main.h"

void cppMain(SPI_HandleTypeDef *hspi, ADC_HandleTypeDef *handle)
{
	protocol protocol(hspi);
	Controller controller(handle);

	for(;;){
		//engine.spiTrans();

		// Read controller values.
		int starttick = HAL_GetTick();

		controller.update();

		if(controller.x < -160){
			protocol.spriteX -= 1;
			protocol.drawSprite(protocol.spriteX, protocol.spriteY);
		}
		else if(controller.y > 0){
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


