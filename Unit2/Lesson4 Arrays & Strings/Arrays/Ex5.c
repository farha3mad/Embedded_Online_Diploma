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

	setvbuf(stdout,NULL,_IONBF,0);
	int arr[20],n,i,num;
	printf("Enter no of elements : ");
	scanf("%d",&n);
	for(i=0 ; i<n ; i++)
		scanf("%d",&arr[i]);

	printf("Enter the element to be searched : ");
	scanf("%d",&num);
	for(i=0 ; i<n ; i++)
	{
		if (arr[i]==num)
		{
			printf("Number found at location = %d",i+1);
			break;
		}
	}
	return 0;
}
