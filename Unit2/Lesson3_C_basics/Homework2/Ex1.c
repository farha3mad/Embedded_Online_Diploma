/*
 ============================================================================
 Name        : Ex1.c
 Author      : Farha Emad
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int x;
	printf("Enter an integer you want to check: ");
	fflush(stdout); fflush(stdin);
	scanf("%d",&x);
	if (x%2 == 0)
	{
		printf("%d is even.",x);
	}
	else
	{
		printf("%d is odd.",x);
	}


	return 0;
}
