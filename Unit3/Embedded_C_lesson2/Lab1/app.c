#include "uart.h"
unsigned char x[100] = "learn_in_depth: <Farha Emad>";
void main(void){
	
	uart_send_string(x);
	
}