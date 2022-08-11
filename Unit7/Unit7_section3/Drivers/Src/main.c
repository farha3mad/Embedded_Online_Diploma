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

void clock_init()
{
	//I/O port A clock enable
	GPIOA_CLOCK_ENABLE();
	//I/O port B clock enable
	GPIOB_CLOCK_ENABLE();
}

int main(void)
{
	clock_init();
	lcd_init();
	seven_segment_init();
	
	lcd_write_word("WELCOME");
	Waiting(200);
	lcd_cmd(LCD_CLEAR);
	
	char ch;
	unsigned char lcd_begin[] = {'1','2','3','4','5','6','7','8','9','0'};
	unsigned char seven_seg_begin[] = {ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,ZERO};
	int i;
	for(i=0 ; i<11 ; i++)
	{
		seven_segment_write(seven_seg_begin[i]);
		lcd_write_char(lcd_begin[i]);
		Waiting(40);
	}
	
	lcd_cmd(LCD_CLEAR);
	lcd_write_word("KEYPAD IS READY");
	Waiting(200);
	lcd_cmd(LCD_CLEAR);
	
	keypad_init();
	while(1)
	{
		ch = keypad_getkey();
		switch(ch)
		{
		case 'A':
			break;
		case '!':
			lcd_cmd(LCD_CLEAR);
			break;
		default:
			lcd_write_char(ch);
			break;
		}
		
		Waiting(1);

	}
}
