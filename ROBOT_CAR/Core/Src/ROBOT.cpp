/*
 * ROBOT.cpp
 * Created on: Oct 17, 2026
 * Author: abdelrhman
 */

#include "ROBOT.hpp"

ROBOT::ROBOT(volatile GPIO_t *select_port, PIN pin1, PIN pin2, PIN pin3, PIN pin4)
{
	PIN pin_array[4] = {pin1, pin2, pin3, pin4};

	for(int i=0;i<4;i++)
	{
   pins[i]=  new PORT_OUT(select_port, pin_array[i], PIN_MODE::General_purpose_output_mode, TYPE::OUTPUT);
	}
	STOP();
}
ROBOT::~ROBOT( )
{
	for(int i = 0; i < 4; i++)
	    {
	        delete pins[i];
	    }
}


void ROBOT::Forword()
{
	pins[0]->ON();
	pins[1]->OFF();
	pins[2]->ON();
	pins[3]->OFF();
}

void ROBOT::Back()
{
	pins[0]->OFF();
	pins[1]->ON();
	pins[2]->OFF();
	pins[3]->ON();
}

void ROBOT::STOP()
{
	pins[0]->OFF();
	pins[1]->OFF();
	pins[2]->OFF();
	pins[3]->OFF();
}


void ROBOT::Right()
{
	pins[0]->OFF();
	pins[1]->OFF();
	pins[2]->OFF();
	pins[3]->ON();
}

void ROBOT::Lift()
{
	pins[0]->ON();
	pins[1]->OFF();
	pins[2]->OFF();
	pins[3]->OFF();
}
