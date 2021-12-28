/*
 ============================================================================
 Name        : Ex8.c
 Author      : Farha Emad
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Strings Ex3
int main(void) {

	setvbuf(stdout,NULL,_IONBF,0);
	char arr[50],temp;
	int i;
	printf("Enter a string : ");
	gets(arr);
	int len = strlen(arr);
	for(i=0 ; i<len/2 ; i++)
	{
		temp = arr[i];
		arr[i] = arr[len-i-1];
		arr[len-i-1] = temp;
	}
	printf("Reverse string is : %s",arr);

	return 0;
}
