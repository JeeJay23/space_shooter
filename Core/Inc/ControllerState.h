/*
 * ControllerState.h
 *
 *  Created on: 15 mrt. 2022
 *      Author: lenna
 */

#ifndef INC_CONTROLLERSTATE_H_
#define INC_CONTROLLERSTATE_H_

#include "main.h"

class ControllerState {
public:
	ControllerState(bool, bool, uint8_t);
	ControllerState() {};
	~ControllerState() {};

public:
	bool buttonUp;
	bool buttonDown;
	uint8_t joystickX;

	// to be implemented
	// uint8_t joystickY;
};


#endif /* INC_CONTROLLERSTATE_H_ */
