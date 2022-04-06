#ifndef INC_CONTROLLERINPUT_H_
#define INC_CONTROLLERINPUT_H_

#include "main.h"
#include "ControllerState.h"

class ControllerInput
{
private:
	double map(int input, int input_start, int input_end, int output_start, int output_end);
	void updateJoyStickValue();
	double getJoyStick(int);

private:
	ADC_HandleTypeDef *hadc;
	volatile uint16_t AD_RES [4];


public:
    ControllerInput(ADC_HandleTypeDef*);
    void update();
	bool buttonUp;
	bool buttonDown;
	double joyStickX;
	double joyStickY;
	double joyStickX2;
	double joyStickY2;
};


#endif /* INC_CONTROLLERINPUT_H_ */
