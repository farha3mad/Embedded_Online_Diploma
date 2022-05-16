/*
 * main.c
 *
 * Created: 5/16/2022 1:40:36 PM
 *  Author: WIN 10
 */ 

/*
 * main.c
 *
 * Created: 5/16/2022 12:55:59 PM
 *  Author: WIN 10
 */ 

#include <xc.h>
#define F_CPU 8000000ul
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

ISR(INT0_vect)
{
	//DDRD = 0xff;
	PORTD |= 1<<5;
	_delay_ms(1000);
	
}

ISR(INT1_vect)
{
	
	PORTD |= 1<<6;
	_delay_ms(1000);
}

ISR(INT2_vect)
{
	
	PORTD |= 1<<7 ;
	_delay_ms(1000);
}
int main(void)
{
	//INT0 any change & INT1 rising edge
	MCUCR |= (1<<0 |  1<<2 | 1<< 3);
	//make sure bit 1 in MCUCR is zero
	MCUCR &= ~(1<<1);
	//INT2 falling edge
	MCUCSR &= ~(1<<6);
	//enable INT0 & INT1 & INT2
	GICR |= (1<<5 |  1<<6 | 1<< 7);
	// enable global interrupt in SREG
	sei(); 
	//make bit5, bit6, bit7 in portD output
	DDRD |= (1<<5) | (1<<6) | (1<<7) ; 
    while(1)
    {	
		//make bit5, bit6, bit7 in portD low
		PORTD &= ~((1<<5) | (1<<6) | (1<<7)) ; 
		_delay_ms(1000);
    }
}
