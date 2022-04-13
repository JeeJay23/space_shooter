/*
 * ControllerInterface.h
 *
 *  Created on: Apr 7, 2022
 *      Author: 31623
 */

#ifndef INC_CONTROLLER_H_
#define INC_CONTROLLER_H_

class Controller {
public:

    virtual void update() = 0;
    double map(double, double, double, double, double);

	bool up;
	bool down;
	double x;

private:
};

inline double Controller::map(double input, double input_start, double input_end, double output_start, double output_end) {
	double slope = 1.0 * (output_end - output_start) / (input_end - input_start);
	return  output_start + slope * (input - input_start);
}

#endif /* INC_CONTROLLER_H_ */
