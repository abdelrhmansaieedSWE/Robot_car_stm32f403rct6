/*
 * ROBOT.hpp
 *
 *  Created on: Oct 17, 2026
 *      Author: abdelrhman
 */

#ifndef INC_ROBOT_HPP_
#define INC_ROBOT_HPP_
#include "GPIO.hpp"

class ROBOT
{
public:
    ROBOT(volatile GPIO_t *select_port, PIN pin1, PIN pin2, PIN pin3, PIN pin4);
    ~ROBOT();

    void Forword();
    void Back();
    void Right();
    void Lift();
    void STOP();
private:
    PORT_OUT *pins[4];
};


#endif /* INC_ROBOT_HPP_ */
