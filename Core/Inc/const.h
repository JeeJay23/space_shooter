/*
 * const.h
 *
 *  Created on: 15 mrt. 2022
 *      Author: 31623
 */

#ifndef INC_CONST_H_
#define INC_CONST_H_

//const bytes
const uint8_t START = 0xEF;
const uint8_t STOP = 0xFE;

//opcodes
enum OPCODE {
	OP_LINE 	= 0x01,
	OP_SPRITE 	= 0x02,
	OP_AUDIO	= 0x03,
	OP_SCORE	= 0x04
};

//number of bytes after size byte used in the protocol
enum PROTOCOL_SIZE
{
	SIZE_LINE 	= 10,
	SIZE_SPRITE	= 7,
	SIZE_AUDIO	= 3,
	SIZE_SCORE	= NULL
};




#endif /* INC_CONST_H_ */
