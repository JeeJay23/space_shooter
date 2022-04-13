#ifndef INC_CONTROLLER_H_
#define INC_CONTROLLER_H_

#include "main.h"

class Controller{
public:
	Controller(int);
	void update();

	bool left;
    bool right;
    bool a;
	bool b;

private:
	void setGPIO(int);
	struct GPIO{
			GPIO_TypeDef* GPIOx;
	    	uint16_t GPIO_Pin;
	} buttonLeft, buttonRight, buttonA, buttonB ;
};

#endif /* INC_CONTROLLER_H_ */
