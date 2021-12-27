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

int main(void) {

	float arr[50] ,sum=0;
	int i,n;
	printf("Enter the numbers of data: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&n);
	for(i=0 ; i<n ; i++)
	{
		printf("%d. Enter number: ",i+1);
		fflush(stdin); fflush(stdout);
		scanf("%f",&arr[i]);
		sum = sum + arr[i];
	}

	printf("Average = %.2f",sum/n);

	return 0;
}
