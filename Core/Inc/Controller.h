#ifndef INC_CONTROLLER_H_
#define INC_CONTROLLER_H_

#include "main.h"

class Controller
{
private:
	double map(int input, int input_start, int input_end, int output_start, int output_end);

private:
	ADC_HandleTypeDef *hadc;
	uint32_t *adc_buf;

public:
    Controller(ADC_HandleTypeDef*, uint32_t*);
    void update();
	bool up;
	bool down;
	double x;
};


#endif /* INC_CONTROLLER_H_ */
