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
		buttonLeft.GPIOx = GPIOA;			// D2
		buttonLeft.GPIO_Pin = GPIO_PIN_10;	// D2
		buttonRight.GPIOx = GPIOB;			// D3
		buttonRight.GPIO_Pin = GPIO_PIN_3;	// D3
		buttonStart.GPIOx = GPIOB; 			// D4
		buttonStart.GPIO_Pin = GPIO_PIN_5;  // D4
		buttonB.GPIOx = GPIOB; 				// D5
		buttonB.GPIO_Pin = GPIO_PIN_4; 		// D5
		buttonA.GPIOx = GPIOB;				// D6
		buttonA.GPIO_Pin = GPIO_PIN_10;		// D6

	}
	else {
		// Controller B
		buttonLeft.GPIOx = GPIOA;			// D7
		buttonLeft.GPIO_Pin = GPIO_PIN_8;	// D7
		buttonRight.GPIOx = GPIOA;			// D8
		buttonRight.GPIO_Pin = GPIO_PIN_9;	// D8
		buttonStart.GPIOx = GPIOC; 			// D9
		buttonStart.GPIO_Pin = GPIO_PIN_7;  // D9
		buttonB.GPIOx = GPIOA; 				// D12
		buttonB.GPIO_Pin = GPIO_PIN_6; 		// D12
		buttonA.GPIOx = GPIOB;				// D14
		buttonA.GPIO_Pin = GPIO_PIN_9;		// D14
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

