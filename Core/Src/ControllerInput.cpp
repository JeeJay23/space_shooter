#include "ControllerInput.h"

ControllerInput::ControllerInput(){

}

double ControllerInput::map(int input, int input_start, int input_end, int output_start, int output_end){
	double slope = 1.0 * (output_end - output_start) / (input_end - input_start);
	return  output_start + slope * (input - input_start);
}

uint8_t ControllerInput::getJoyStick(){

}
