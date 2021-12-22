/*
 ============================================================================
 Name        : Ex6.c
 Author      : Farha Emad
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int n, i, sum=0;
	printf("Enter an integer: ");
	fflush(stdout); fflush(stdin);
	scanf("%d",&n);
	for(i=1 ; i<=n ;i++)
	{
		sum += i;
	}
	printf("Sum = %d",sum);

	return 0;
}
