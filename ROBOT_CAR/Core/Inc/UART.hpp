/*
 * UART.hpp
 *
 *  Created on: Oct 16, 2026
 *      Author: abdelrhman
 */

#ifndef INC_UART_HPP_
#define INC_UART_HPP_

#include "Bit_Math.hpp"
#define UART1 ((volatile UART_conf*) 0x40011000)

typedef struct
{
	 u32 SR;
	 u32 DR;
	 u32 BRR;
	 u32 CR1;
	 u32 CR2;
	 u32 CR3;
	 u32 GTPR;


}UART_conf;
void UART_INIT();
void Send(char c);
void Send(const char *ptr);
int Read();





#endif /* INC_UART_HPP_ */
