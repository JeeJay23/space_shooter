#include <Controller.h>

/**
  * @brief  set controllerNumber to 0 or 1 for selecting pins.
  */
Controller::Controller(int controllerNumber){
	setGPIO(controllerNumber);
}

void Controller::setGPIO(int controllerNumber){
	if(controllerNumber){
		// TODO set correct pin numbers
		buttonLeft.GPIOx = GPIOA;
		buttonLeft.GPIO_Pin = GPIO_PIN_9;
		buttonRight.GPIOx = GPIOA;
		buttonRight.GPIO_Pin = GPIO_PIN_9;
		buttonA.GPIOx = GPIOA;
		buttonA.GPIO_Pin = GPIO_PIN_9;
		buttonB.GPIOx = GPIOA;
		buttonB.GPIO_Pin = GPIO_PIN_9;
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
	}
}

void Controller::update(){
	// Buttons are active high, so invert them with some bitwise magic.
	left = (HAL_GPIO_ReadPin(buttonLeft.GPIOx, buttonLeft.GPIO_Pin) ^ 1);
	right = (HAL_GPIO_ReadPin(buttonRight.GPIOx, buttonRight.GPIO_Pin) ^ 1);
	a = (HAL_GPIO_ReadPin(buttonA.GPIOx, buttonA.GPIO_Pin) ^ 1);
	b = (HAL_GPIO_ReadPin(buttonB.GPIOx, buttonB.GPIO_Pin) ^ 1);
}

