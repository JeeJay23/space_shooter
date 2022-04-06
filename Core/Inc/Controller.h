#ifndef INC_CONTROLLER_H_
#define INC_CONTROLLER_H_

#include "main.h"

class Controller
{
private:
	double map(int input, int input_start, int input_end, int output_start, int output_end);
	double getJoyStick(int);

private:
	ADC_HandleTypeDef *hadc;
	volatile uint16_t adc_buf [4];

public:
    Controller(ADC_HandleTypeDef*);
    void update();
	bool up;
	bool down;
	double x;
	double y;
};


#endif /* INC_CONTROLLER_H_ */
