/*
 ============================================================================
 Name        : Ex7.c
 Author      : Farha Emad
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int n, i, fact =1;
	printf("Enter an integer: ");
	fflush(stdout); fflush(stdin);
	scanf("%d",&n);
	if (n<0)
	{
		printf("Erorr!!! Factorial of negative number doesn't exist.");
	}
	else if (n==0 || n==1)
	{
		fact = 1;
		printf("Factorial = %d",fact);
	}
	else
	{
		for(i=n ; i>0 ; i--)
		{
			fact *= i;
		}
		printf("Factorial = %d",fact);
	}

	return 0;
}
