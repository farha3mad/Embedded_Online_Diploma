/*
 ============================================================================
 Name        : q3.c
 Author      : Farha Emad
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
	setvbuf(stdout,NULL,_IONBF,0);
	char arr[50];
	char* ptr = arr;
	int i;
	printf("Input a string :");
	gets(arr);
	 /* increment pointer until it points to the last character in the string */
	while(*(ptr+1) != '\0')
	{
		++ptr;
	}
	char temp;
	 /* swapping characters of the string */
	for(i=0 ; i<strlen(arr)/2 ;i++)
	{
		temp = arr[i];
		arr[i] = *ptr;
		*ptr = temp;
		--ptr;
	}
	printf("Reverse of the string is : %s",arr);
	return 0;
}
