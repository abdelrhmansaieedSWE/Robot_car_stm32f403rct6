/*
 * UART.cpp
 *
 *  Created on: Oct 16, 2026
 *      Author: abdelrhman
 */
#include "UART.hpp"
#define FOCS 16000000


void UART_INIT()
{
	UART1->CR1 |= (1<<2) | (1<<3);
	UART1->BRR = (FOCS + 9600/2) / 9600;

	UART1->CR1 |= (1<<13);
}
void Send(char c)
{
	while (!(UART1->SR & (1 << 7)));
	UART1->DR =c;
}
void Send(const char *ptr)
{
	while(*ptr!='\0')
	{
		Send(*ptr);
		ptr++;
	}
}
int Read()
{
	while (!(UART1->SR & (1 << 5)));
	return UART1->DR;
}

