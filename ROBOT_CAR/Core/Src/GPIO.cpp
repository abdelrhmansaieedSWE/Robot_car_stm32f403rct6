/*
 * GPIO.cpp
 *
 *  Created on: Oct 16, 2026
 *      Author: abdelrhman
 */
#include "GPIO.hpp"

PORT_OUT::PORT_OUT(volatile GPIO_t *select_port, PIN pin, PIN_MODE pin_mode, TYPE outOR_input)
    : select_port(select_port), outOR_input(outOR_input)
{
    this->pin = static_cast<int>(pin);
    this->pin_mode = static_cast<int>(pin_mode);

    select_port->MODER &= ~(0x3u << (this->pin * 2));
    select_port->MODER |=  (static_cast<u32>(this->pin_mode) << (this->pin * 2));

    if (pin_mode == PIN_MODE::Input)
    {
        select_port->PUPDR &= ~(0x3u << (this->pin * 2));
        select_port->PUPDR |=  (pull_type << (this->pin * 2));
    }
    else if (pin_mode == PIN_MODE::General_purpose_output_mode)
    {
        select_port->OTYPER &= ~(1u << this->pin);           // push-pull
        select_port->OSPEEDR &= ~(0x3u << (this->pin * 2));
        select_port->OSPEEDR |=  (3u << (this->pin * 2));
    }
    else if (pin_mode == PIN_MODE::Alternate_function_mode)
    {
        select_port->OTYPER &= ~(1u << this->pin);           // push-pull
        select_port->OSPEEDR &= ~(0x3u << (this->pin * 2));
        select_port->OSPEEDR |=  (3u << (this->pin * 2));

        if (outOR_input == TYPE::INPUT)
        {
            select_port->PUPDR &= ~(0x3u << (this->pin * 2));
            select_port->PUPDR |=  (PULL_UP << (this->pin * 2));
        }

        if (this->pin < 8)
        {
            select_port->AFRL &= ~(0xFu << (this->pin * 4));
            select_port->AFRL |=  (7u << (this->pin * 4));
        }
        else
        {
            select_port->AFRH &= ~(0xFu << ((this->pin - 8) * 4));
            select_port->AFRH |=  (7u << ((this->pin - 8) * 4));
        }
    }
}

PORT_OUT::~PORT_OUT()
{
}

void PORT_OUT::ON()
{
    select_port->BSRR = (1u << pin);
}

void PORT_OUT::OFF()
{
    select_port->BSRR = (1u << (pin + 16));
}

int PORT_OUT::read()
{
    return ((select_port->IDR >> pin) & 1);
}
