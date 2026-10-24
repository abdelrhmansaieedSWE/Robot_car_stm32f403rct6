/*
 * RCC.hpp
 *
 *  Created on: Oct 16, 2026
 *      Author: abdelrhman
 */

#ifndef RCC_HPP_
#define RCC_HPP_
#include "Bit_Math.hpp"
#define RCC_BASE 0x40023800
#define RCC_APB2_REG  (*(volatile u32*)(RCC_BASE+0x44))
#define RCC_AHB1ER_REG (*(volatile u32*)(RCC_BASE+0x30))

enum class Port_
{
 PORTA,
 PORTB,
 PORTC
};
enum class UART_ENR
{
	USART1=4,
	USART6,
	ADC1=8,
	SPI1=12
};
class RCC_AHP1ENR
{
public:

	RCC_AHP1ENR(Port_ select);
};

class RCC_APB2ENR
{
public:

    RCC_APB2ENR(UART_ENR select);
};


#endif /* RCC_HPP_ */

