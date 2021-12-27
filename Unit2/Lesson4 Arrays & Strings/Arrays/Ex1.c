/*
 ============================================================================
 Name        : Ex1.c
 Author      : Farha Emad
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//Arrays Ex1
int main(void) {
	float a[2][2];
	float b[2][2];
	int i,j;
	printf("Enter the elements of 1st matrix\n");
	for (i=0 ; i<2 ;i++)
	{
		for (j=0 ; j<2 ; j++)
		{
			printf("Enter a%d%d: ",i+1,j+1);
			fflush(stdin); fflush(stdout);
			scanf("%f",&a[i][j]);
		}
	}
	printf("Enter the elements of 2nd matrix\n");
	for (i=0 ; i<2 ;i++)
	{
		for (j=0 ; j<2 ; j++)
		{
			printf("Enter b%d%d: ",i+1,j+1);
			fflush(stdin); fflush(stdout);
			scanf("%f",&b[i][j]);
		}
	}
	printf("\nSum Of Matrix:\n");
	for (i=0 ; i<2 ;i++)
	{
		for (j=0 ; j<2 ; j++)
		{
			printf("%.1f\t",a[i][j]+b[i][j]);
		}
		printf("\n");
	}
	return 0;
}
