/*
 ============================================================================
 Name        : q4.c
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
	int arr[15];
	int size,i;
	int* ptr = arr;
	printf("Input the number of elements to store in the array (max 15) :");
	scanf("%d",&size);
	printf("Input 5 number of elements in the array :\n");
	for(i=0 ; i<size ; i++)
	{
		printf("element - %d :",i);
		scanf("%d",&arr[i]);
		if(i != size-1)    /* increment the pointer until it reaches the last element */
			++ptr;
	}
	printf("The elements of array in reverse order are : \n");
	for(i=0 ; i<size ; i++)
	{
		printf("element - %d : %d \n",i,*ptr);
		ptr--;
	}

	return 0;
}
