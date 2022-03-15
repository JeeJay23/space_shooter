/*
 * engine.h
 *
 *  Created on: 15 mrt. 2022
 *      Author: 31623
 */

#ifndef INC_ENGINE_H_
#define INC_ENGINE_H_

#include "main.h"

class engine {
public:
	engine(SPI_HandleTypeDef*);
	~engine();

	void spiTrans();

private:
	SPI_HandleTypeDef *spi1;
};



#endif /* INC_ENGINE_H_ */
