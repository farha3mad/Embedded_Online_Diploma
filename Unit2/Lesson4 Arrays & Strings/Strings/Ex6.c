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
#include <string.h>
//String Ex1
int main(void) {

	setvbuf(stdout,NULL,_IONBF,0);
	char arr[50],letter;
	int i,count=0;
	printf("Enter a string: ");
	gets(arr);
	printf("Enter a character to find frequency: ");
	scanf("%c",&letter);
	for(i=0 ; i<strlen(arr) ; i++)
	{
		if (arr[i] == letter)
		{
			count++;
		}
	}
	printf("Frequency of %c = %d",letter,count);


	return 0;
}
