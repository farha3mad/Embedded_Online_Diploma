/*
 *        file: KeyPad.c
 *  Created on: ١٠‏/٠٨‏/٢٠٢٢
 *      Author: Eng.Farha
 */

#include "KeyPad.h"

GPIO_Pin_Config_t pincg;

int keypad_rows[] = {R0,R1,R2,R3};
int keypad_columns[] = {C0,C1,C2,C3};

void keypad_init(){

	//configure keypad pins output mode

	pincg.GPIO_PinConfig = GPIO_PIN_MODE_OUTPUT_PP;
	pincg.GPIO_PinNumber = keypad_rows[0];
	pincg.GPIO_Output_Speed = GPIO_PIN_SPEED_10MHZ;
	MCAL_GPIO_init(KEYPAD_PORT, &pincg);

	pincg.GPIO_PinConfig = GPIO_PIN_MODE_OUTPUT_PP;
	pincg.GPIO_PinNumber = keypad_rows[1];
	pincg.GPIO_Output_Speed = GPIO_PIN_SPEED_10MHZ;
	MCAL_GPIO_init(KEYPAD_PORT, &pincg);

	pincg.GPIO_PinConfig = GPIO_PIN_MODE_OUTPUT_PP;
	pincg.GPIO_PinNumber = keypad_rows[2];
	pincg.GPIO_Output_Speed = GPIO_PIN_SPEED_10MHZ;
	MCAL_GPIO_init(KEYPAD_PORT, &pincg);

	pincg.GPIO_PinConfig = GPIO_PIN_MODE_OUTPUT_PP;
	pincg.GPIO_PinNumber = keypad_rows[3];
	pincg.GPIO_Output_Speed = GPIO_PIN_SPEED_10MHZ;
	MCAL_GPIO_init(KEYPAD_PORT, &pincg);

	pincg.GPIO_PinConfig = GPIO_PIN_MODE_OUTPUT_PP;
	pincg.GPIO_PinNumber = keypad_columns[0];
	pincg.GPIO_Output_Speed = GPIO_PIN_SPEED_10MHZ;
	MCAL_GPIO_init(KEYPAD_PORT, &pincg);

	pincg.GPIO_PinConfig = GPIO_PIN_MODE_OUTPUT_PP;
	pincg.GPIO_PinNumber = keypad_columns[1];
	pincg.GPIO_Output_Speed = GPIO_PIN_SPEED_10MHZ;
	MCAL_GPIO_init(KEYPAD_PORT, &pincg);

	pincg.GPIO_PinConfig = GPIO_PIN_MODE_OUTPUT_PP;
	pincg.GPIO_PinNumber = keypad_columns[2];
	pincg.GPIO_Output_Speed = GPIO_PIN_SPEED_10MHZ;
	MCAL_GPIO_init(KEYPAD_PORT, &pincg);

	pincg.GPIO_PinConfig = GPIO_PIN_MODE_OUTPUT_PP;
	pincg.GPIO_PinNumber = keypad_columns[3];
	pincg.GPIO_Output_Speed = GPIO_PIN_SPEED_10MHZ;
	MCAL_GPIO_init(KEYPAD_PORT, &pincg);

    //initially all bits are high 0->8
	MCAL_GPIO_WritePort(KEYPAD_PORT, 0x01FF);

}

char keypad_getkey(){

	int i,j;
	for(i=0 ; i<4 ; i++){

		//at first all columns high
		MCAL_GPIO_WritePin(KEYPAD_PORT, keypad_columns[0], GPIO_PIN_STATE_HIGH);
		MCAL_GPIO_WritePin(KEYPAD_PORT, keypad_columns[1], GPIO_PIN_STATE_HIGH);
		MCAL_GPIO_WritePin(KEYPAD_PORT, keypad_columns[2], GPIO_PIN_STATE_HIGH);
		MCAL_GPIO_WritePin(KEYPAD_PORT, keypad_columns[3], GPIO_PIN_STATE_HIGH);

		//choose one column to be be tested
		MCAL_GPIO_WritePin(KEYPAD_PORT, keypad_columns[i], GPIO_PIN_STATE_LOW);

		for(j=0 ; j<4 ; j++)
		{
			if((MCAL_GPIO_ReadPin(KEYPAD_PORT, keypad_rows[j]))==0) //switch is pressed
			{
				while((MCAL_GPIO_ReadPin(KEYPAD_PORT, keypad_rows[j]))==0);
				switch(i)
				{
				//first row
				case 0:
				{
					if(j==0) return '7';
					else if (j==1) return '4';
					else if (j==2) return '1';
					else if (j==3) return '!';
					break;
				}
				//second row
				case 1:
				{
					if(j==0) return '8';
					else if (j==1) return '5';
					else if (j==2) return '2';
					else if (j==3) return '0';
					break;
				}
				//third row
				case 2:
				{
					if(j==0) return '9';
					else if (j==1) return '6';
					else if (j==2) return '3';
					else if (j==3) return '=';
					break;
				}
				//fourth row
				case 3:
				{
					if(j==0) return '/';
					else if (j==1) return '*';
					else if (j==2) return '-';
					else if (j==3) return '+';
					break;
				}
				}
			}
		}
	}
	return 'A';
}
