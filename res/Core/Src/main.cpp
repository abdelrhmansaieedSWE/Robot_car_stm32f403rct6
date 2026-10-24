#include "Bit_Math.hpp"
#include "RCC.hpp"
#include "GPIO.hpp"
#include "UART.hpp"
#include "ROBOT.hpp"

int main()
{

    RCC_AHP1ENR En0(Port_::PORTA);
    RCC_APB2ENR ENUART1(UART_ENR::USART1);
    PORT_OUT TX(GPIOA,PIN::pin9,PIN_MODE::Alternate_function_mode,TYPE::OUTPUT);
    PORT_OUT RX(GPIOA,PIN::pin10,PIN_MODE::Alternate_function_mode,TYPE::INPUT);

    PORT_OUT ptest(GPIOA,PIN::pin4,PIN_MODE::General_purpose_output_mode,TYPE::OUTPUT);
    PORT_OUT ptest1(GPIOA,PIN::pin5,PIN_MODE::General_purpose_output_mode,TYPE::OUTPUT);

    ROBOT R1(GPIOA,PIN::pin0,PIN::pin1,PIN::pin2,PIN::pin3);

    PORT_OUT p1(GPIOA,PIN::pin0,PIN_MODE::General_purpose_output_mode,TYPE::OUTPUT);

    UART_INIT();


	while(1)
	{

		p1.ON();

	int read=Read();
	if(read=='F')
		{

		R1.Forword();
		ptest.ON();
		ptest1.OFF();

		for(int i=0;i<500000;i++);
		}
	else if(read=='B')
		{
		R1.Back();
		for(int i=0;i<500000;i++);
		}
	else if(read=='L')
		{
		R1.Lift();
		for(int i=0;i<500000;i++);
		}
	else if(read=='R')
		{
		R1.Right();
		for(int i=0;i<500000;i++);
		}
	else
		{
		R1.STOP();

		}



	}

	return 0;
}
