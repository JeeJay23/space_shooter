/*
 * SPIController.h
 *
 *  Created on: Apr 7, 2022
 *      Author: 31623
 */

#ifndef CPPMAIN_SRC_SPICONTROLLER_H_
#define CPPMAIN_SRC_SPICONTROLLER_H_

#include <Controller.h>
#include "main.h"

class SPIController: public Controller {
public:
	SPIController(SPI_HandleTypeDef*);
	virtual ~SPIController();

private:
	void update() override;
	SPI_HandleTypeDef *hspi;

};

#endif /* CPPMAIN_SRC_SPICONTROLLER_H_ */
