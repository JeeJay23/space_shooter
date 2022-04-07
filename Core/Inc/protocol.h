/*
 * engine.h
 *
 *  Created on: 15 mrt. 2022
 *      Author: 31623
 */

#ifndef INC_PROTOCOL_H_
#define INC_PROTOCOL_H_

#include "main.h"
#include "const.h"


class Protocol {
public:
	Protocol(SPI_HandleTypeDef*);
	~Protocol();

	void drawSprite(unsigned int, unsigned int);
	void drawLine();
	void playAudio();
	unsigned int spriteX = 500, spriteY = 300;

private:
	SPI_HandleTypeDef *spi1;

};



#endif /* INC_PROTOCOL_H_ */
