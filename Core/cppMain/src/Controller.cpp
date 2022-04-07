#include <Controller.h>

Controller::Controller(ADC_HandleTypeDef *handle, uint32_t *buffer) : hadc(handle), adc_buf(buffer){
}

double Controller::map(int input, int input_start, int input_end, int output_start, int output_end){

	double slope = (output_end - output_start) / (input_end - input_start);
	return  output_start + slope * (input - input_start) - 85; // offset because joystick isnt perfectly centered
}

void Controller::update(){
	// start adc conversion
	HAL_ADC_Start_DMA(hadc, adc_buf, 1);

	//Convert output -180 to 180
	map(*adc_buf, 0, 1023, -180, 180);

	// Buttons are active high, so invert them with some bitwise magic.
	down = (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_9) ^ 1);
	btnA = (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_8)^ 1);
}
