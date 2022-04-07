/*
 * engine.cpp
 *
 *  Created on: Mar 15, 2022
 *      Author: 31623
 */

#include <math.h>
#include <Protocol.h>

Protocol::Protocol(SPI_HandleTypeDef *hspi) : spi1(hspi)
{}

Protocol::~Protocol(){};

//void engine::spiTrans()
//{
//	  //int i = 7;
//	  for(int j = 0; j < 10; j++){
//		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);
//		  HAL_Delay(1000);
//		  HAL_SPI_Transmit(spi1, (uint8_t *)&j, 1, 100);
//		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET);
//	  }
//}

//TODO: header with constants;
void Protocol::drawSprite(unsigned int sprite_x, unsigned int sprite_y)
{
	uint8_t buff[8] = {0b11101111,
						SIZE_SPRITE,
						0b00000010,
						(uint8_t)sprite_x & 0xff,
						(uint8_t)(sprite_x >> 8) & 0xff,
						(uint8_t)sprite_y & 0xff,
						(uint8_t)(sprite_y >> 8) & 0xff,
						0b11111110
	};



	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);

	HAL_SPI_Transmit(spi1, buff, sizeof(buff), 100);

//	HAL_SPI_Transmit(spi1, (uint8_t*)0b11101111, 8, 100);
//	HAL_SPI_Transmit(spi1, (uint8_t*)SIZE_SPRITE, 8, 100);
//	HAL_SPI_Transmit(spi1, (uint8_t*)0b00000010, 8, 100);
//	HAL_SPI_Transmit(spi1, (uint8_t*)(sprite_x & 0xff), 8, 100);
//	HAL_SPI_Transmit(spi1, (uint8_t*)((sprite_x >> 8) & 0xff), 8, 100);
//	HAL_SPI_Transmit(spi1, (uint8_t*)(sprite_y & 0xff), 8, 100);
//	HAL_SPI_Transmit(spi1, (uint8_t*)((sprite_y >> 8) & 0xff), 8, 100);
//	HAL_SPI_Transmit(spi1, (uint8_t*)STOP, 8, 100);

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET);
}






