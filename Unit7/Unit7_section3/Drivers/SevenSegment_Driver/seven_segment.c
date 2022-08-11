/*
 * 		  file: seven_segment.c
 *  Created on: ١١‏/٠٨‏/٢٠٢٢
 *      Author: Eng.Farha
 */

#include "seven_segment.h"

GPIO_Pin_Config_t pincg;

void seven_segment_init(){

	//configure 7-segment pins to be output

	pincg.GPIO_PinConfig = GPIO_PIN_MODE_OUTPUT_PP;
	pincg.GPIO_PinNumber = SEVENSEG_A;
	pincg.GPIO_Output_Speed = GPIO_PIN_SPEED_10MHZ;
	MCAL_GPIO_init(SEVENSEG_PORT, &pincg);

	pincg.GPIO_PinConfig = GPIO_PIN_MODE_OUTPUT_PP;
	pincg.GPIO_PinNumber = SEVENSEG_B;
	pincg.GPIO_Output_Speed = GPIO_PIN_SPEED_10MHZ;
	MCAL_GPIO_init(SEVENSEG_PORT, &pincg);

	pincg.GPIO_PinConfig = GPIO_PIN_MODE_OUTPUT_PP;
	pincg.GPIO_PinNumber = SEVENSEG_C;
	pincg.GPIO_Output_Speed = GPIO_PIN_SPEED_10MHZ;
	MCAL_GPIO_init(SEVENSEG_PORT, &pincg);

	pincg.GPIO_PinConfig = GPIO_PIN_MODE_OUTPUT_PP;
	pincg.GPIO_PinNumber = SEVENSEG_D;
	pincg.GPIO_Output_Speed = GPIO_PIN_SPEED_10MHZ;
	MCAL_GPIO_init(SEVENSEG_PORT, &pincg);

	pincg.GPIO_PinConfig = GPIO_PIN_MODE_OUTPUT_PP;
	pincg.GPIO_PinNumber = SEVENSEG_E;
	pincg.GPIO_Output_Speed = GPIO_PIN_SPEED_10MHZ;
	MCAL_GPIO_init(SEVENSEG_PORT, &pincg);

	pincg.GPIO_PinConfig = GPIO_PIN_MODE_OUTPUT_PP;
	pincg.GPIO_PinNumber = SEVENSEG_F;
	pincg.GPIO_Output_Speed = GPIO_PIN_SPEED_10MHZ;
	MCAL_GPIO_init(SEVENSEG_PORT, &pincg);

	pincg.GPIO_PinConfig = GPIO_PIN_MODE_OUTPUT_PP;
	pincg.GPIO_PinNumber = SEVENSEG_G;
	pincg.GPIO_Output_Speed = GPIO_PIN_SPEED_10MHZ;
	MCAL_GPIO_init(SEVENSEG_PORT, &pincg);

	//initially all leds are off
//	MCAL_GPIO_WritePort(SEVENSEG_PORT, 0xFF<<9);

}

void seven_segment_write(uint16_t number)
{
	MCAL_GPIO_WritePort(SEVENSEG_PORT, number<<9);

}
