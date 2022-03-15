#include "ControllerInput.h"

ControllerInput::ControllerInput(ADC_HandleTypeDef *handle, uint32_t *buffer) : hadc(handle), AD_RES(buffer){
}

double ControllerInput::map(int input, int input_start, int input_end, int output_start, int output_end){
	double slope = 1.0 * (output_end - output_start) / (input_end - input_start);
	return  output_start + slope * (input - input_start);
}

void ControllerInput::updateJoyStickValue(){
	HAL_ADC_Start_DMA(hadc, AD_RES, 1);
}

uint8_t ControllerInput::getJoyStick(){
	// Input from 1023 to 0 (inverted because joystick is inverted)
	// Output 0 - 255
	return map(*AD_RES, 1023, 0, 0, 255);
}

ControllerState* ControllerInput::getControllerState(){
	ControllerState *state  = new ControllerState();
	state->joystickX = getJoyStick();
	state->buttonDown = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_9);
	state->buttonUp = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_8);
	return state;
}
