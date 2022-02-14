/*
 ============================================================================
 Name        : q2.c
 Author      : Farha Emad
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	char c = 65;    /*  ACSII code of character A  */
	char* ptr = &c;
	int i;
	printf("The Alphabets are : \n");
	for(i=0 ; i<26 ; i++)
	{
		printf("%c  ",*ptr);
		++*ptr;     /*  increment the value of c  */
	}

	return 0;
}
