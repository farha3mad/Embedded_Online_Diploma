/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Eng.Farha
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "stm32f103x6.h"
#include "STM32F103C6_GPIO_Driver.h"

void clock_init()
{
	//I/O port A clock enable
	GPIOA_CLOCK_ENABLE();
	//I/O port B clock enable
	GPIOB_CLOCK_ENABLE();
}

void GPIO_init()
{
	GPIO_Pin_Config_t pincg;

	/***PortA1***/
	//MODE: 00: Input mode
	//CNF: 01: Floating input
	pincg.GPIO_PinConfig = GPIO_PIN_MODE_INPUT_FLOA;
	pincg.GPIO_PinNumber = GPIO_PIN_1;
	MCAL_GPIO_init(GPIOA, &pincg);

	/***PortA13***/
	//MODE: 00: Input mode
	//CNF: 01: Floating input
	pincg.GPIO_PinConfig = GPIO_PIN_MODE_INPUT_FLOA;
	pincg.GPIO_PinNumber = GPIO_PIN_13;
	MCAL_GPIO_init(GPIOA, &pincg);

	/***PortB1***/
	//MODE: 01: Output mode, max speed 10 MHz.
	//CNF: 00: General purpose output push-pull.
	pincg.GPIO_PinConfig = GPIO_PIN_MODE_OUTPUT_PP;
	pincg.GPIO_PinNumber = GPIO_PIN_1;
	pincg.GPIO_Output_Speed = GPIO_PIN_SPEED_10MHZ;
	MCAL_GPIO_init(GPIOB, &pincg);

	/***PortB13***/
	//MODE: 01: Output mode, max speed 10 MHz.
	//CNF: 00: General purpose output push-pull.
	pincg.GPIO_PinConfig = GPIO_PIN_MODE_OUTPUT_PP;
	pincg.GPIO_PinNumber = GPIO_PIN_13;
	pincg.GPIO_Output_Speed = GPIO_PIN_SPEED_10MHZ;
	MCAL_GPIO_init(GPIOB, &pincg);

}

void Waiting(unsigned int x)
{
	int i,j;
	for(i=0 ; i<x ; i++)
		for(j=0 ; j<255 ; j++);

}

int main(void)
{
	clock_init();
	GPIO_init();

	while(1)
	{
		if(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0)
		{
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1);
			//To make it single press
			while(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0);
		}

		if(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_13) == 1)
		{
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_13);
		}

		Waiting(1);

	}
}
