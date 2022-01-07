/*
 ============================================================================
 Name        : Ex4.c
 Author      : Farha Emad
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int Power(int base, int pow);

int main(void) {
	setvbuf(stdout,NULL,_IONBF,0);
	int base,pow;
	printf("Enter base number: ");
	scanf("%d",&base);
	printf("Enter power number(positive integer): ");
	scanf("%d",&pow);
	printf("%d^%d = %d",base,pow,Power(base,pow));
	return 0;
}

int Power(int base, int pow)
{
	if(pow < 1)
		return 1;
	while(pow >= 1)
		return base*Power(base,pow-1);
}
