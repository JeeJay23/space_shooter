#ifndef INC_ADCCONTROLLER_H_
#define INC_ADCCONTROLLER_H_

#include "Controller.h"
#include "main.h"

class ADCController : public Controller
{
private:
//	double map(double input, double input_start, double input_end, double output_start, double output_end);

private:
	ADC_HandleTypeDef *hadc;
	uint32_t *adc_buf;

public:
    ADCController(ADC_HandleTypeDef*, uint32_t*);
    void update() override;
};


#endif /* INC_ADCCONTROLLER_H_ */
