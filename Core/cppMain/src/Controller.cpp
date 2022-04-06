#include <Controller.h>

Controller::Controller(ADC_HandleTypeDef *handle) : hadc(handle){
	HAL_ADC_Start_DMA(handle, (uint32_t*)adc_buf, 4);
}

double Controller::map(int input, int input_start, int input_end, int output_start, int output_end){

	double slope = (output_end - output_start) / (input_end - input_start);
	return  output_start + slope * (input - input_start);
}

double Controller::getJoyStick(int joystick){
	//Convert output -180 to 180
	return map(adc_buf[joystick], 0, 1023, -180, 180);
}

void Controller::update(){

	//ControllerState *state  = new ControllerState();

	// start adc conversion
	x = getJoyStick(0);
	y = getJoyStick(1);
	// Buttons are active high, so invert them with some bitwise magic.

	down = (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_9) ^ 1);
	up = (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_8)^ 1);
}
