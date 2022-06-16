#include "lifo.h"
unsigned int buffer1[5];
void main()
{
	int i,temp =0;
	unsigned int* buffer2 = (unsigned int*)malloc(5*sizeof(unsigned int));
	lifo_buff_t UART_lifo, I2C_lifo;
	
	lifo_init(&UART_lifo,buffer1,5);
	lifo_init(&I2C_lifo,buffer2,5);
	
	for(i=0 ; i<5 ; i++)
	{
		if(lifo_push(&UART_lifo,i) == lifo_no_error)
			printf("UART_lifo add : %d\n",i);		
	}
	
	for(i=0 ; i<5 ; i++)
	{
		if(lifo_pop(&UART_lifo,&temp) == lifo_no_error)
			printf("UART_lifo pop : %d\n",temp);		
	}
	
}