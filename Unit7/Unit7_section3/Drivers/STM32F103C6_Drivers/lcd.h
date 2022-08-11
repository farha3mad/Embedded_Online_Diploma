#ifndef _LCD_H
#define _LCD_H

#include "stm32"

#define LCD_PORT PORTA
#define LCD_PORT_DIRCTION DDRA
#define LCD_CTRL PORTB
#define LCD_CTRL_DIRCTION DDRB

//control pins
#define RS 1
#define RW 2
#define EN 3

#define DATA_SHIFT 4
#define FOUR_BIT_MODE
//#define EIGHT_BIT_MODE

//LCD commands
#define LCD_FUNCTION_8BIT_2LINES (0x38)
#define LCD_FUNCTION_4BIT_2LINES (0x28)
#define LCD_ENTRY_MODE (0x06)
#define LCD_DISPLAY_OFF_CURSOR_OFF (0x08)
#define LCD_CURSOR_ON (0x0E)
#define LCD_CURSOR_OFF (0x0C)
#define LCD_CURSOR_BLINKING (0x0F)
#define LCD_CLEAR (0x01) 
#define LCD_BEGIN_AT_FIRST_ROW (0x80) 
#define LCD_BEGIN_AT_SECOND_ROW (0xC0)

//Functions prototypes
void lcd_init();
void lcd_cmd(unsigned char command);
void lcd_write_char(unsigned char ch);
void lcd_write_word(unsigned char *data);
void lcd_is_busy();
void lcd_goto_xy(int row,int position);

#endif