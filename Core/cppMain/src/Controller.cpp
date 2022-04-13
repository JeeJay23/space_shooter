#include <Controller.h>

/**
  * @brief  set controllerNumber to 0 or 1 for selecting pins.
  */
Controller::Controller(int controllerNumber){
	setGPIO(controllerNumber);
}

void Controller::setGPIO(int controllerNumber){
	if(!controllerNumber){
		// Controller A
		buttonLeft.GPIOx = GPIOA;			// D0
		buttonLeft.GPIO_Pin = GPIO_PIN_3;	// D0
		buttonRight.GPIOx = GPIOA;			// D1
		buttonRight.GPIO_Pin = GPIO_PIN_2;	// D1
		buttonA.GPIOx = GPIOA;				// D2
		buttonA.GPIO_Pin = GPIO_PIN_10;		// D2
		buttonB.GPIOx = GPIOB; 				// D3
		buttonB.GPIO_Pin = GPIO_PIN_3; 		// D3
		buttonStart.GPIOx = GPIOB; 			// D4
		buttonStart.GPIO_Pin = GPIO_PIN_5; 	// D4
	}
	else {
		// TODO set correct pin numbers
		buttonLeft.GPIOx = GPIOA;
		buttonLeft.GPIO_Pin = GPIO_PIN_9;
		buttonRight.GPIOx = GPIOA;
		buttonRight.GPIO_Pin = GPIO_PIN_9;
		buttonA.GPIOx = GPIOA;
		buttonA.GPIO_Pin = GPIO_PIN_9;
		buttonB.GPIOx = GPIOA;
		buttonB.GPIO_Pin = GPIO_PIN_9;
		buttonStart.GPIOx = GPIOA;
		buttonStart.GPIO_Pin = GPIO_PIN_9;
	}
}

void Controller::update(){
	// Buttons are active high, so invert them with some bitwise magic.
	left = 	(HAL_GPIO_ReadPin(buttonLeft.GPIOx, buttonLeft.GPIO_Pin) ^ 1);
	right = (HAL_GPIO_ReadPin(buttonRight.GPIOx, buttonRight.GPIO_Pin) ^ 1);
	a = 	(HAL_GPIO_ReadPin(buttonA.GPIOx, buttonA.GPIO_Pin) ^ 1);
	b = 	(HAL_GPIO_ReadPin(buttonB.GPIOx, buttonB.GPIO_Pin) ^ 1);
	start = (HAL_GPIO_ReadPin(buttonStart.GPIOx, buttonStart.GPIO_Pin) ^ 1);
}

