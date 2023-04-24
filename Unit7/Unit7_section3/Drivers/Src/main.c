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
#include "LCD.h"
#include "KeyPad.h"
#include "seven_segment.h"
#include "STM32F103C6_EXTI_Driver.h"

void clock_init()
{
	//I/O port A clock enable
	GPIOA_CLOCK_ENABLE();
	//I/O port B clock enable
	GPIOB_CLOCK_ENABLE();
}

int main(void)
{
	
	EXTI_PinConfig_t e1 ;
	e1.EXTI_PIN = EXTI0PA0;

		while(1){
		Waiting(1);
		}

}
