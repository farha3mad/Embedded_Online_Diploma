/*
 *        file: LCD.c
 *  Created on: ٠٨‏/٠٨‏/٢٠٢٢
 *      Author: Eng.Farha
 */

#include "LCD.h"

GPIO_Pin_Config_t pincg;

void Waiting(unsigned int x)
{
	int i,j;
	for(i=0 ; i<x ; i++)
		for(j=0 ; j<255 ; j++);

}

void lcd_kick(){

	MCAL_GPIO_WritePin(LCD_CTRL, EN, 1);
	Waiting(20);
	MCAL_GPIO_WritePin(LCD_CTRL, EN, 0);
}

void lcd_is_busy(){

#ifdef EIGHT_BIT_MODE

	//input mode for all 8 bits

	pincg.GPIO_PinConfig = GPIO_PIN_MODE_INPUT_FLOA;
	pincg.GPIO_PinNumber = GPIO_PIN_0;
	MCAL_GPIO_init(LCD_PORT, &pincg);

	pincg.GPIO_PinConfig = GPIO_PIN_MODE_INPUT_FLOA;
	pincg.GPIO_PinNumber = GPIO_PIN_1;
	MCAL_GPIO_init(LCD_PORT, &pincg);

	pincg.GPIO_PinConfig = GPIO_PIN_MODE_INPUT_FLOA;
	pincg.GPIO_PinNumber = GPIO_PIN_2;
	MCAL_GPIO_init(LCD_PORT, &pincg);

	pincg.GPIO_PinConfig = GPIO_PIN_MODE_INPUT_FLOA;
	pincg.GPIO_PinNumber = GPIO_PIN_3;
	MCAL_GPIO_init(LCD_PORT, &pincg);

	pincg.GPIO_PinConfig = GPIO_PIN_MODE_INPUT_FLOA;
	pincg.GPIO_PinNumber = GPIO_PIN_4;
	MCAL_GPIO_init(LCD_PORT, &pincg);

	pincg.GPIO_PinConfig = GPIO_PIN_MODE_INPUT_FLOA;
	pincg.GPIO_PinNumber = GPIO_PIN_5;
	MCAL_GPIO_init(LCD_PORT, &pincg);

	pincg.GPIO_PinConfig = GPIO_PIN_MODE_INPUT_FLOA;
	pincg.GPIO_PinNumber = GPIO_PIN_6;
	MCAL_GPIO_init(LCD_PORT, &pincg);

	pincg.GPIO_PinConfig = GPIO_PIN_MODE_INPUT_FLOA;
	pincg.GPIO_PinNumber = GPIO_PIN_7;
	MCAL_GPIO_init(LCD_PORT, &pincg);


#endif

/*
#ifdef FOUR_BIT_MODE
	LCD_PORT_DIRCTION &= ~(0xFF << DATA_SHIFT); //input mode for higher 4 bits
#endif
	 */

	pincg.GPIO_PinConfig = GPIO_PIN_MODE_OUTPUT_PP;
	pincg.GPIO_PinNumber = RS;
	pincg.GPIO_Output_Speed = GPIO_PIN_SPEED_10MHZ;
	MCAL_GPIO_init(LCD_CTRL, &pincg);

	pincg.GPIO_PinConfig = GPIO_PIN_MODE_OUTPUT_PP;
	pincg.GPIO_PinNumber = RW;
	pincg.GPIO_Output_Speed = GPIO_PIN_SPEED_10MHZ;
	MCAL_GPIO_init(LCD_CTRL, &pincg);

	pincg.GPIO_PinConfig = GPIO_PIN_MODE_OUTPUT_PP;
	pincg.GPIO_PinNumber = EN;
	pincg.GPIO_Output_Speed = GPIO_PIN_SPEED_10MHZ;
	MCAL_GPIO_init(LCD_CTRL, &pincg);

	MCAL_GPIO_WritePin(LCD_CTRL, RS, 0);
	MCAL_GPIO_WritePin(LCD_CTRL, RW, 1); //read mode
	lcd_kick();

	//output mode
	pincg.GPIO_PinConfig = GPIO_PIN_MODE_OUTPUT_PP;
	pincg.GPIO_PinNumber = GPIO_PIN_0;
	pincg.GPIO_Output_Speed = GPIO_PIN_SPEED_10MHZ;
	MCAL_GPIO_init(LCD_PORT, &pincg);

	pincg.GPIO_PinConfig = GPIO_PIN_MODE_OUTPUT_PP;
	pincg.GPIO_PinNumber = GPIO_PIN_1;
	pincg.GPIO_Output_Speed = GPIO_PIN_SPEED_10MHZ;
	MCAL_GPIO_init(LCD_PORT, &pincg);

	pincg.GPIO_PinConfig = GPIO_PIN_MODE_OUTPUT_PP;
	pincg.GPIO_PinNumber = GPIO_PIN_2;
	pincg.GPIO_Output_Speed = GPIO_PIN_SPEED_10MHZ;
	MCAL_GPIO_init(LCD_PORT, &pincg);

	pincg.GPIO_PinConfig = GPIO_PIN_MODE_OUTPUT_PP;
	pincg.GPIO_PinNumber = GPIO_PIN_3;
	pincg.GPIO_Output_Speed = GPIO_PIN_SPEED_10MHZ;
	MCAL_GPIO_init(LCD_PORT, &pincg);

	pincg.GPIO_PinConfig = GPIO_PIN_MODE_OUTPUT_PP;
	pincg.GPIO_PinNumber = GPIO_PIN_4;
	pincg.GPIO_Output_Speed = GPIO_PIN_SPEED_10MHZ;
	MCAL_GPIO_init(LCD_PORT, &pincg);

	pincg.GPIO_PinConfig = GPIO_PIN_MODE_OUTPUT_PP;
	pincg.GPIO_PinNumber = GPIO_PIN_5;
	pincg.GPIO_Output_Speed = GPIO_PIN_SPEED_10MHZ;
	MCAL_GPIO_init(LCD_PORT, &pincg);

	pincg.GPIO_PinConfig = GPIO_PIN_MODE_OUTPUT_PP;
	pincg.GPIO_PinNumber = GPIO_PIN_6;
	pincg.GPIO_Output_Speed = GPIO_PIN_SPEED_10MHZ;
	MCAL_GPIO_init(LCD_PORT, &pincg);

	pincg.GPIO_PinConfig = GPIO_PIN_MODE_OUTPUT_PP;
	pincg.GPIO_PinNumber = GPIO_PIN_7;
	pincg.GPIO_Output_Speed = GPIO_PIN_SPEED_10MHZ;
	MCAL_GPIO_init(LCD_PORT, &pincg);

	MCAL_GPIO_WritePin(LCD_CTRL, RW, 0); //write mode

}

void lcd_init(){

	Waiting(20);
	lcd_is_busy();

	//output mode

	//MODE: 01: Output mode, max speed 10 MHz.
	//CNF: 00: General purpose output push-pull.
	pincg.GPIO_PinConfig = GPIO_PIN_MODE_OUTPUT_PP;
	pincg.GPIO_PinNumber = RS;
	pincg.GPIO_Output_Speed = GPIO_PIN_SPEED_10MHZ;
	MCAL_GPIO_init(LCD_CTRL, &pincg);

	pincg.GPIO_PinConfig = GPIO_PIN_MODE_OUTPUT_PP;
	pincg.GPIO_PinNumber = RW;
	pincg.GPIO_Output_Speed = GPIO_PIN_SPEED_10MHZ;
	MCAL_GPIO_init(LCD_CTRL, &pincg);

	pincg.GPIO_PinConfig = GPIO_PIN_MODE_OUTPUT_PP;
	pincg.GPIO_PinNumber = EN;
	pincg.GPIO_Output_Speed = GPIO_PIN_SPEED_10MHZ;
	MCAL_GPIO_init(LCD_CTRL, &pincg);

	//low for control pins
	MCAL_GPIO_WritePin(LCD_CTRL, EN, 0);
	MCAL_GPIO_WritePin(LCD_CTRL, RS, 0);
	MCAL_GPIO_WritePin(LCD_CTRL, RW, 0);

	//output mode
	pincg.GPIO_PinConfig = GPIO_PIN_MODE_OUTPUT_PP;
	pincg.GPIO_PinNumber = GPIO_PIN_0;
	pincg.GPIO_Output_Speed = GPIO_PIN_SPEED_10MHZ;
	MCAL_GPIO_init(LCD_PORT, &pincg);

	pincg.GPIO_PinConfig = GPIO_PIN_MODE_OUTPUT_PP;
	pincg.GPIO_PinNumber = GPIO_PIN_1;
	pincg.GPIO_Output_Speed = GPIO_PIN_SPEED_10MHZ;
	MCAL_GPIO_init(LCD_PORT, &pincg);

	pincg.GPIO_PinConfig = GPIO_PIN_MODE_OUTPUT_PP;
	pincg.GPIO_PinNumber = GPIO_PIN_2;
	pincg.GPIO_Output_Speed = GPIO_PIN_SPEED_10MHZ;
	MCAL_GPIO_init(LCD_PORT, &pincg);

	pincg.GPIO_PinConfig = GPIO_PIN_MODE_OUTPUT_PP;
	pincg.GPIO_PinNumber = GPIO_PIN_3;
	pincg.GPIO_Output_Speed = GPIO_PIN_SPEED_10MHZ;
	MCAL_GPIO_init(LCD_PORT, &pincg);

	pincg.GPIO_PinConfig = GPIO_PIN_MODE_OUTPUT_PP;
	pincg.GPIO_PinNumber = GPIO_PIN_4;
	pincg.GPIO_Output_Speed = GPIO_PIN_SPEED_10MHZ;
	MCAL_GPIO_init(LCD_PORT, &pincg);

	pincg.GPIO_PinConfig = GPIO_PIN_MODE_OUTPUT_PP;
	pincg.GPIO_PinNumber = GPIO_PIN_5;
	pincg.GPIO_Output_Speed = GPIO_PIN_SPEED_10MHZ;
	MCAL_GPIO_init(LCD_PORT, &pincg);

	pincg.GPIO_PinConfig = GPIO_PIN_MODE_OUTPUT_PP;
	pincg.GPIO_PinNumber = GPIO_PIN_6;
	pincg.GPIO_Output_Speed = GPIO_PIN_SPEED_10MHZ;
	MCAL_GPIO_init(LCD_PORT, &pincg);

	pincg.GPIO_PinConfig = GPIO_PIN_MODE_OUTPUT_PP;
	pincg.GPIO_PinNumber = GPIO_PIN_7;
	pincg.GPIO_Output_Speed = GPIO_PIN_SPEED_10MHZ;
	MCAL_GPIO_init(LCD_PORT, &pincg);

	Waiting(20);
	lcd_cmd(LCD_CLEAR);

#ifdef EIGHT_BIT_MODE
	lcd_cmd(LCD_FUNCTION_8BIT_2LINES);
#endif

	/*
#ifdef FOUR_BIT_MODE
	lcd_cmd(0x02);
	lcd_cmd(LCD_FUNCTION_4BIT_2LINES);
#endif
	 */
	 
	lcd_cmd(LCD_ENTRY_MODE);
	lcd_cmd(LCD_CURSOR_BLINKING);
	lcd_cmd(LCD_BEGIN_AT_FIRST_ROW);
}

void lcd_goto_xy(int row,int position){

	if(row == 0)
	{
		if(position<16 && position>=0){
			lcd_cmd(LCD_BEGIN_AT_FIRST_ROW+position);
		}
	}
	else if(row == 1)
	{
		if(position<16 && position>=0){
			lcd_cmd(LCD_BEGIN_AT_SECOND_ROW+position);
		}
	}
}

void lcd_cmd(unsigned char command){
	lcd_is_busy();

#ifdef EIGHT_BIT_MODE

	MCAL_GPIO_WritePort(LCD_PORT, command);
	MCAL_GPIO_WritePin(LCD_CTRL, RW, 0); //write mode
	MCAL_GPIO_WritePin(LCD_CTRL, RS, 0); //command
	lcd_kick();
#endif

	/*
#ifdef FOUR_BIT_MODE
	LCD_PORT = (LCD_PORT & 0x0F) | (command & (0xFF<<DATA_SHIFT));
	reset_bit(LCD_CTRL,RW); //write mode
	reset_bit(LCD_CTRL,RS); //command
	Waiting(1);
	lcd_kick();
	LCD_PORT = (LCD_PORT & 0x0F) | (command << DATA_SHIFT);
	reset_bit(LCD_CTRL,RW); //write mode
	reset_bit(LCD_CTRL,RS); //command
	Waiting(1);
	lcd_kick();
#endif
	 */
}

void lcd_write_char(unsigned char ch){

	lcd_is_busy();

#ifdef EIGHT_BIT_MODE
	MCAL_GPIO_WritePort(LCD_PORT, ch);
	MCAL_GPIO_WritePin(LCD_CTRL, RW, 0); //write mode
	MCAL_GPIO_WritePin(LCD_CTRL, RS, 1); //data
	lcd_kick();
#endif
	/*
#ifdef FOUR_BIT_MODE
	LCD_PORT = (LCD_PORT & 0x0F) | (ch & (0xFF<<DATA_SHIFT));
	reset_bit(LCD_CTRL,RW); //write mode
	set_bit(LCD_CTRL,RS); //command
	Waiting(1);
	lcd_kick();
	LCD_PORT = (LCD_PORT & 0x0F) | (ch & (0xFF>>DATA_SHIFT));
	reset_bit(LCD_CTRL,RW); //write mode
	set_bit(LCD_CTRL,RS); //command
	Waiting(1);
	lcd_kick();
#endif
	 */
}

void lcd_write_word(unsigned char *data){

	lcd_is_busy();
	
#ifdef EIGHT_BIT_MODE
	int i;
	MCAL_GPIO_WritePin(LCD_CTRL, RW, 0); //write mode
	MCAL_GPIO_WritePin(LCD_CTRL, RS, 1); //data
	for(i=0 ; data[i] !='\0' ; i++)
	{
		if(i==16)
		{
			lcd_cmd(LCD_BEGIN_AT_SECOND_ROW);
		}
		else if(i==33)
		{
			lcd_cmd(LCD_CLEAR);
			lcd_cmd(LCD_BEGIN_AT_FIRST_ROW);
		}

		lcd_write_char(data[i]);
	}

#endif

}