/*
 ============================================================================
 Name        : Ex4.c
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
	int arr[20],n,i,position,num;
	printf("Enter no of elements : ");
	scanf("%d",&n);
	for(i=0 ; i<n ; i++)
		scanf("%d",&arr[i]);

	printf("Enter the element to be inserted : ");
	scanf("%d",&num);
	printf("Enter the location : ");
	scanf("%d",&position);
	for(i=n ; i>=position-1 ; i--)
		arr[i+1] = arr[i];

	arr[position-1] = num;
	for(i=0 ; i<n+1 ; i++)
		printf("%d ",arr[i]);

	return 0;
}
