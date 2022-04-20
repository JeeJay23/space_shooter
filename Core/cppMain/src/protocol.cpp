/*
 * engine.cpp
 *
 *  Created on: Mar 15, 2022
 *      Author: 31623
 */

#include <math.h>
#include <Protocol.h>
#include "globals.h"

Protocol::Protocol(SPI_HandleTypeDef *hspi) : spi1(hspi)
{}

Protocol::~Protocol(){};

void Protocol::drawSprite(unsigned int sprite_x, unsigned int sprite_y, unsigned int count)
{
	uint8_t buff[9] = {0b11101111,
						SIZE_SPRITE,
						0b00000001,
						(uint8_t)count & 0xff,
						(uint8_t)sprite_x + FRONT_PORCH & 0xff,
						(uint8_t)(sprite_x + FRONT_PORCH >> 8) & 0xff,
						(uint8_t)sprite_y + VERT_PORCH & 0xff,
						(uint8_t)(sprite_y + VERT_PORCH >> 8) & 0xff,
						0b11111110
	};

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);
	HAL_SPI_Transmit(spi1, buff, sizeof(buff), 100);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET);
}






