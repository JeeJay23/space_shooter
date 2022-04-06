#include "ControllerInput.h"

ControllerInput::ControllerInput(ADC_HandleTypeDef *handle) : hadc(handle){
}

double ControllerInput::map(int input, int input_start, int input_end, int output_start, int output_end){

	double slope = 1.0 * (output_end - output_start) / (input_end - input_start);
	return  output_start + slope * (input - input_start);
}

void ControllerInput::updateJoyStickValue(){
	HAL_ADC_Start_DMA(hadc, (uint32_t*)AD_RES, 4);
}

double ControllerInput::getJoyStick(int joystick){
	//Convert output -180 to 180
	return map(AD_RES[joystick], 0, 1023, -180, 180);
}

void ControllerInput::update(){

	//ControllerState *state  = new ControllerState();
	updateJoyStickValue();
	joyStickX = getJoyStick(0);
	joyStickY = getJoyStick(1);
	joyStickX2 = getJoyStick(2);
	joyStickY2 = getJoyStick(3);
	// Buttons are active high, so invert them with some bitwise magic.
	buttonDown = (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_9) ^ 1);
	buttonUp = (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_8)^ 1);
}
