/*
 ============================================================================
 Name        : q1.c
 Author      : Farha Emad
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char m = 29;
	printf("Address of m : 0x%x \n",&m);
	printf("Value of m : %d \n",m);

	char* ab = &m;
	printf("\nNow ab is assigned with the address of m.\n");
	printf("Address of pointer ab : 0x%x \n",ab);
	printf("Content of pointer ab : %d \n",*ab);

	m = 34;
	printf("\nThe value of m assigned to 34 now.\n");
	printf("Address of pointer ab : 0x%x \n",ab);
	printf("Content of pointer ab : %d \n",*ab);

	*ab = 7;
	printf("\nThe pointer variable ab is assigned with the value 7 now.\n");
	printf("Address of m : 0x%x \n",&m);
	printf("Value of m : %d \n",m);
	return 0;
}
