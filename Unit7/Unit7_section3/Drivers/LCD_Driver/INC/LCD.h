/*
 * 		  file: LCD.h
 *  Created on: ٠٨‏/٠٨‏/٢٠٢٢
 *      Author: Eng.Farha
 */

#ifndef INC_LCD_H_
#define INC_LCD_H_

#include "stm32f103x6.h"
#include "STM32F103C6_GPIO_Driver.h"

#define LCD_PORT 			GPIOA
#define LCD_CTRL 			GPIOA

//control pins
#define RS 					GPIO_PIN_8
#define RW 					GPIO_PIN_9
#define EN 					GPIO_PIN_10

#define DATA_SHIFT    4
//#define FOUR_BIT_MODE
#define EIGHT_BIT_MODE

//LCD commands
#define LCD_FUNCTION_8BIT_2LINES 	(0x38)
#define LCD_FUNCTION_4BIT_2LINES 	(0x28)
#define LCD_ENTRY_MODE 				(0x06)
#define LCD_DISPLAY_OFF_CURSOR_OFF  (0x08)
#define LCD_CURSOR_ON 				(0x0E)
#define LCD_CURSOR_OFF				(0x0C)
#define LCD_CURSOR_BLINKING 		(0x0F)
#define LCD_CLEAR					(0x01)
#define LCD_BEGIN_AT_FIRST_ROW 		(0x80)
#define LCD_BEGIN_AT_SECOND_ROW 	(0xC0)

//Functions prototypes
void lcd_init();
void lcd_cmd(unsigned char command);
void lcd_write_char(unsigned char ch);
void lcd_write_word(unsigned char *data);
void lcd_is_busy();
void lcd_goto_xy(int row,int position);
void Waiting(unsigned int x);

#endif /* INC_LCD_H_ */
