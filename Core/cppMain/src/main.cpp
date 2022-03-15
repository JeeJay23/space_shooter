/*
 * main.cpp
 *
 *  Created on: Mar 15, 2022
 *      Author: 31623
 */

#include "main.h"
#include "engine.h"

void cppMain(SPI_HandleTypeDef *hspi)
{
	engine engine(hspi);
	for(;;){
		engine.spiTrans();
	}
}


