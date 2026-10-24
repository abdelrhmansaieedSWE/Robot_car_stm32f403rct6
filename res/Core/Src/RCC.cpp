/*
 * RCC.cpp
 *
 *  Created on: Oct 16, 2026
 *      Author: abdelrhman
 */
#include "RCC.hpp"

	RCC_AHP1ENR::RCC_AHP1ENR(Port_ select)
	{
		RCC_AHB1ER_REG |=(1<<static_cast<int>(select));
	}

	RCC_APB2ENR::RCC_APB2ENR(UART_ENR select)
	 {
		 RCC_APB2_REG |=(1<<static_cast<int>(select));
	 }

