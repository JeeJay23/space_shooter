#include "ControllerState.h"

ControllerState::ControllerState(bool _buttonUp, bool _buttonDown, uint8_t _joystickX){
	buttonUp = _buttonUp;
	buttonDown = _buttonDown;
	joystickX = _joystickX;
}
