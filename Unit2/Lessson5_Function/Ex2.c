/*
 ============================================================================
 Name        : Ex2.c
 Author      : Farha Emad
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int factorial (int x);

int main(void) {
	setvbuf(stdout,NULL,_IONBF,0);
	int x;
	printf("Enter a positive integer: ");
	scanf("%d",&x);
	printf("Factorial of %d = %d",x,factorial(x));
	return 0;
}

int factorial(int x)
{
	if(x==1 || x==0)
		return 1;

	while(x>1)
		return x*factorial(x-1);
}
