/*
 ============================================================================
 Name        : Ex3.c
 Author      : Farha Emad
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	float a, b, c;
	printf("Enter three numbers: ");
	fflush(stdout); fflush(stdin);
	scanf("%f %f %f",&a, &b, &c);
	float max1 = (a>b)? a : b;
	float max2 = (max1>c)? max1 : c;
	printf("Largest number = %f",max2);

	return 0;
}
