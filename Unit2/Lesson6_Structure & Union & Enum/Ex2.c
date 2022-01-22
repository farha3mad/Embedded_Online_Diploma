/*
 ============================================================================
 Name        : Ex2.c
 Author      : Farha Emad
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
struct distance {
	int feet;
	float inch;
};

void SUM (struct distance x ,struct distance y);
int main(void) {
	setvbuf(stdout,NULL,_IONBF,0);
	struct distance x,y;
	printf("Enter information of the 1st distance\n");
	printf("Enter feet:");
	scanf("%d",&x.feet);
	printf("Enter inch:");
	scanf("%f",&x.inch);
	printf("\nEnter information of the 2nd distance\n");
	printf("Enter feet:");
	scanf("%d",&y.feet);
	printf("Enter inch:");
	scanf("%f",&y.inch);
	SUM(x,y);
	return 0;
}
void SUM (struct distance x ,struct distance y)
{
	struct distance result;
	result.feet = x.feet + y.feet;
	if (x.inch + y.inch >= 12)     //if the sum of the inches>=12 that will make a feet.(feet = 12 inch)
	{
		++result.feet;
		result.inch = (x.inch + y.inch)-12;
	}
	else
	{
		result.inch = x.inch + y.inch;
	}
	printf("Sum of distances= %d\'-%.1f\"",result.feet,result.inch);
}
