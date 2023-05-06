/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
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

#include "../STM32F103_Drivers/INC/stm32f103x6.h"
#include "../STM32F103_Drivers/INC/STM32F103C6_RCC_DRIVER.h"
#include "../STM32F103_Drivers/INC/STM32F103C6_GPIO_Driver.h"
#include "../STM32F103_Drivers/INC/STM32F103C6_USART_DRIVER.h"

void clock_init(void)
{
	GPIOA_CLOCK_ENABLE() ;
	GPIOB_CLOCK_ENABLE() ;
	AFIO_CLOCK_ENABLE()  ;
}

unsigned char data ;

int main(void)
{
	clock_init();

	USART_config config;
	config.USART_BAUD_RATE  = USART_BAUDRATE_115200;
	config.USART_HWFlowCtrl = USART_HW_FLOWCONTROL_NONE;
	config.USART_MODE 		= USART_MODE_TX_RX;
	config.USART_PARITY_BIT = USART_PARITY_NONE;
	config.USART_PAYLOAD 	= USART_PAYLOAD_8 ;
	config.USART_STOP_BIT   = USART_STOP_BIT_1;
	config.USART_IRQ		= USART_IRQ_ENABLE_NONE;

	MCAL_USART_init(USART1,&config);
	MCAL_GPIO_USART_SetPins(USART1);

	while(1)
	{

		MCAL_USART_ReceiveData(USART1 , &data , enable);
		MCAL_USART_SendData(USART1 , &data , enable);


	}
}