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
#include <string.h>
void Reverse(void);

int main(void) {
	setvbuf(stdout,NULL,_IONBF,0);
	printf("Enter a sentence: ");
	Reverse();
	return 0;
}

void Reverse(void)
{
	char c ;
	scanf("%c",&c);
	if(c != '\n')
	{
		Reverse();
	printf("%c",c);
	}

}
