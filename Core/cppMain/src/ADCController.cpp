#include <ADCController.h>
#include <vector>

ADCController::ADCController(ADC_HandleTypeDef *handle, uint32_t *buffer) : hadc(handle), adc_buf(buffer){
}

//double ADCController::map(double input, double input_start, double input_end, double output_start, double output_end){
//
//	double slope = (output_end - output_start) / (input_end - input_start);
//	return  output_start + slope * (input - input_start);
//}

void ADCController::update(){
	// start adc conversion
	HAL_ADC_Start_DMA(hadc, adc_buf, 1);

	//Convert output -180 to 180
	x = map((double)*adc_buf, 0, 1023, -180, 180);

	// Buttons are active high, so invert them with some bitwise magic.
	down = (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_9) ^ 1);
	up = (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_8)^ 1);
}

