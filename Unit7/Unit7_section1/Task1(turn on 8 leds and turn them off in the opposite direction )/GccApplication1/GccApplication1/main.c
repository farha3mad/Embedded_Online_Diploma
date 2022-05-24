/*
 * GccApplication1.c
 *
 * Created: 22/05/2022 07:07:49 م
 * Author : WIN 10
 */ 

#include "Utils.h"
#include "MemoryMap1.h"
#include "util/delay.h"

int main(void)
{
    DDRA = 0xFF;
    while (1) 
    {
		set_bit(PortA,0);
		_delay_ms(500);
		set_bit(PortA,1);
		_delay_ms(500);
		set_bit(PortA,2);
		_delay_ms(500);
		set_bit(PortA,3);
		_delay_ms(500);
		set_bit(PortA,4);
		_delay_ms(500);
		set_bit(PortA,5);
		_delay_ms(500);
		set_bit(PortA,6);
		_delay_ms(500);
		set_bit(PortA,7);
		_delay_ms(500);
		
		reset_bit(PortA,7);
		_delay_ms(500);
		reset_bit(PortA,6);
		_delay_ms(500);
		reset_bit(PortA,5);
		_delay_ms(500);
		reset_bit(PortA,4);
		_delay_ms(500);
		reset_bit(PortA,3);
		_delay_ms(500);
		reset_bit(PortA,2);
		_delay_ms(500);
		reset_bit(PortA,1);
		_delay_ms(500);
		reset_bit(PortA,0);
		_delay_ms(500);
    }
}

