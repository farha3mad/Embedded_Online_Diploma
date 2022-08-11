/*
 *    	  file: seven_segment.h
 *  Created on: ١١‏/٠٨‏/٢٠٢٢
 *      Author: Eng.Farha
 */

#ifndef INC_SEVEN_SEGMENT_H_
#define INC_SEVEN_SEGMENT_H_

#include "stm32f103x6.h"
#include "STM32F103C6_GPIO_Driver.h"

#define SEVENSEG_PORT	GPIOB

#define SEVENSEG_A		GPIO_PIN_9
#define SEVENSEG_B		GPIO_PIN_10
#define SEVENSEG_C		GPIO_PIN_11
#define SEVENSEG_D		GPIO_PIN_12
#define SEVENSEG_E		GPIO_PIN_13
#define SEVENSEG_F		GPIO_PIN_14
#define SEVENSEG_G		GPIO_PIN_15

#define ZERO 			0x01
#define ONE  	 		0x79
#define TWO 	 		0x24
#define THREE  	 		0x30
#define FOUR 	 		0x4C
#define FIVE 	 		0x12
#define SIX 	 		0x02
#define SEVEN  	 		0x19
#define EIGHT 	 		0x00
#define NINE	 		0x10

void seven_segment_init();
void seven_segment_write(uint16_t number);

#endif /* INC_SEVEN_SEGMENT_H_ */
