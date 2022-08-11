/*
 * 		  file: KeyPad.h
 *  Created on: ١٠‏/٠٨‏/٢٠٢٢
 *      Author: Eng.Farha
 */

#ifndef INC_KEYPAD_H_
#define INC_KEYPAD_H_

#include "stm32f103x6.h"
#include "STM32F103C6_GPIO_Driver.h"

#define KEYPAD_PORT 	GPIOB

#define R0 				GPIO_PIN_0
#define R1 				GPIO_PIN_1
#define R2 				GPIO_PIN_3
#define R3 				GPIO_PIN_4
#define C0 				GPIO_PIN_5
#define C1				GPIO_PIN_6
#define C2 				GPIO_PIN_7
#define C3 				GPIO_PIN_8

void keypad_init();
char keypad_getkey();

#endif /* INC_KEYPAD_H_ */
