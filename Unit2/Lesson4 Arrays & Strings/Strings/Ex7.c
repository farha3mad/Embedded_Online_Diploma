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
//Strings Ex2
int main(void) {

	setvbuf(stdout,NULL,_IONBF,0);
	char arr[50];
	int i=0;
	printf("Enter a string: ");
	gets(arr);
	while(arr[i] != '\0')
	{
		i++;
	}
	printf("Length of string: %d",i);

	return 0;
}
