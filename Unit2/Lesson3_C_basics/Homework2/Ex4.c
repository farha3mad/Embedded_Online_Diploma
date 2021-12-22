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

int main(void) {

	float x;
	printf("Enter a number: ");
	fflush(stdout); fflush(stdin);
	scanf("%f",&x);
	if(x>0)
	{
		printf("%f is positive.",x);
	}
	else if (x<0)
	{
		printf("%f is negative.",x);
	}
	else
	{
		printf("You entered zero.");
	}


	return 0;
}
