/*
- GPIO.hpp
 *
-  Created on:
Oct 16, 2026
-      Author:
abdelrhman
 */

#ifndef INC_GPIO_HPP_
#define INC_GPIO_HPP_
#include "Bit_Math.hpp"

#define GPIOA ((volatile GPIO_t*)0x40020000)
#define GPIOB ((volatile GPIO_t*)0x40020400)
#define GPIOC ((volatile GPIO_t*)0x40020800)

#define PULL_UP   1
#define PULL_Down 3
#define NO_pull   0

#define pull_type (PULL_UP)

	typedef struct
	{
		volatile u32 MODER;
		volatile u32 OTYPER;
		volatile u32 OSPEEDR;
		volatile u32 PUPDR;
		volatile u32 IDR;
		volatile u32 ODR;
		volatile u32 BSRR;
		volatile u32 LCKR;
		volatile u32 AFRL;
		volatile u32 AFRH;
	}GPIO_t;

	enum class PIN {
		 pin0, pin1, pin2, pin3,
		 pin4, pin5, pin6, pin7,
		 pin8, pin9, pin10, pin11,
		 pin12, pin13, pin14, pin15
	};

	enum class PIN_MODE {
		 Input = 0x0,
		 General_purpose_output_mode = 0x1,
		 Alternate_function_mode = 0x2,
		 Analog_mode = 0x3,
	};

	enum class TYPE {
		 INPUT,
		 OUTPUT,
	};

	class PORT_OUT {
	public:
	    PORT_OUT(volatile GPIO_t *select_port, PIN pin, PIN_MODE pin_mode, TYPE outOR_input);
	   ~PORT_OUT();

	   void ON();
	   void OFF();
	   int read();
	private:
	   volatile GPIO_t *select_port;
	   int pin;
	   int pin_mode;
	   TYPE outOR_input;
	};

#endif /* INC_GPIO_HPP_ */
