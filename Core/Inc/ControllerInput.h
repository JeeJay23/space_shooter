#ifndef INC_CONTROLLERINPUT_H_
#define INC_CONTROLLERINPUT_H_

#include "main.h"
#include "ControllerState.h"

class ControllerInput
{
private:
	double map(int input, int input_start, int input_end, int output_start, int output_end);
	void updateJoyStickValue();
	uint8_t getJoyStick();

private:
	ADC_HandleTypeDef *hadc;
	uint32_t *AD_RES;


public:
    ControllerInput(ADC_HandleTypeDef*, uint32_t*);
    void getControllerState();
	bool buttonUp;
	bool buttonDown;
	uint8_t joyStickX;
};


#endif /* INC_CONTROLLERINPUT_H_ */
