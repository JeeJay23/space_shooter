/*
 * main.cpp
 *
 *  Created on: Mar 15, 2022
 *      Author: 31623
 */

#include "main.h"
#include "engine.h"
#include "ControllerInput.h"

void cppMain(SPI_HandleTypeDef *hspi, ADC_HandleTypeDef *handle, uint32_t *buffer)
{
	engine engine(hspi);
	ControllerInput controller(handle, buffer);

	for(;;){
		//engine.spiTrans();

		// Read controller values.
		ControllerState *state = controller.getControllerState();
	}
}


