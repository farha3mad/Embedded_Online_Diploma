/*
 * task2.c
 *
 * Created: 24/05/2022 05:19:35 ص
 * Author : WIN 10
 */ 

#include "Utils.h"
#include "MemoryMap1.h"
#include "util/delay.h"

int main(void)
{
    DDRD = 0;
	DDRA = 0xFF;
	PORTA =0;
	int i=0;
    while (1) 
    {
		if(i>7)
		{
			PORTA = 0;
			i=0;
		}	
		if(read_bit(PIND,0) == 0)
		{
			_delay_ms(25);
			set_bit(PORTA,i);
			i++;
			while(read_bit(PIND,0) == 0);
		}
    }
}

