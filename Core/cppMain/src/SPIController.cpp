/*
 * SPIController.cpp
 *
 *  Created on: Apr 7, 2022
 *      Author: 31623
 */

#include "SPIController.h"


SPIController::SPIController(SPI_HandleTypeDef *hspi) : hspi(hspi)  {
	// TODO Auto-generated constructor stub

}

SPIController::~SPIController() {
	// TODO Auto-generated destructor stub
}

void SPIController::update() {

	int spiTrans = 0;
	HAL_SPI_TransmitReceive(hspi, (uint8_t*)spiTrans, (uint8_t*)spiReceive, 3, 100);

	x = map((double)spiReceive[0], 0, 1023, -180, 180);

	down = spiReceive[1] ^ 1;
	up = spiReceive[2] ^ 1;



}
