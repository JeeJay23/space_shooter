#ifndef INC_CONTROLLERINPUT_H_
#define INC_CONTROLLERINPUT_H_

class ControllerInput
{
private:
	double map(int input, int input_start, int input_end, int output_start, int output_end);


public:
    ControllerInput();
    bool getButtonState(int button);
    uint8_t getJoyStick();
};


#endif /* INC_CONTROLLERINPUT_H_ */
