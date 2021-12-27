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

int main(void) {

	int a[5][5];
	int i,j,r,c;
	printf("Enter rows and columns of matrix: ");
	fflush(stdin); fflush(stdout);
	scanf("%d %d",&r,&c);
	printf("Enter elements of matrix: \n");
	for(i=0 ; i<r ; i++)
	{
		for(j=0 ; j<c ; j++)
		{
			printf("Enter elements a%d%d: " ,i+1,j+1);
			fflush(stdin); fflush(stdout);
			scanf("%d",&a[i][j]);
		}
	}
	printf("\nEntered Matrix:\n");
	for(i=0 ; i<r ; i++)
	{
		for(j=0 ; j<c ; j++)
		{
			printf("%d  ",a[i][j]);
		}
		printf("\n\n");
	}
	printf("Transpose of Matrix:\n");
	for(i=0 ; i<c ; i++)
	{
		for(j=0 ; j<r ; j++)
		{
			printf("%d  ",a[j][i]);
		}
		printf("\n\n");
	}

	return 0;
}
