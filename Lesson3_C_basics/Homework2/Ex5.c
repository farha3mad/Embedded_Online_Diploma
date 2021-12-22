/*
 ============================================================================
 Name        : Ex5.c
 Author      : Farha Emad
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	char c;
	printf("Enter a character: ");
	fflush(stdout); fflush(stdin);
	scanf("%c",&c);
	if ((c>=65 && c<=90) || (c>=97 && c<=122))
	{
		printf("%c is an alphabet.",c);
	}
	else
	{
		printf("%c is not an alphabet.",c);
	}


	return 0;
}
