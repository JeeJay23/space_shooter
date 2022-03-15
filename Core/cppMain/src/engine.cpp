/*
 * engine.cpp
 *
 *  Created on: Mar 15, 2022
 *      Author: 31623
 */

#include "engine.h"

engine::engine(SPI_HandleTypeDef *hspi) : spi1(hspi)
{}

engine::~engine(){};

void engine::spiTrans()
{
	  //int i = 7;
	  for(int j = 0; j < 10; j++){
		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);
		  HAL_Delay(1000);
		  HAL_SPI_Transmit(spi1, (uint8_t *)&j, 1, 100);
		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET);
	  }
}




