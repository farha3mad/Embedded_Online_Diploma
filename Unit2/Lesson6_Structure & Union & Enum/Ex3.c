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
struct complex {
	float real;
	float imaginary;
};
void SUM(struct complex x , struct complex y);
int main(void) {
	setvbuf(stdout,NULL,_IONBF,0);
	struct complex x;
	struct complex y;
	printf("For 1st complex number\n");
	printf("Enter real and imaginary respectively: ");
	scanf("%f %f",&x.real,&x.imaginary);
	printf("\nFor 2nd complex number\n");
	printf("Enter real and imaginary respectively: ");
	scanf("%f %f",&y.real,&y.imaginary);
	SUM(x,y);
	return 0;
}
void SUM(struct complex x , struct complex y)
{
	struct complex result;
	result.real = x.real + y.real;
	result.imaginary = x.imaginary + y.imaginary;
	printf("Sum=%.1f+%.1fi",result.real,result.imaginary);

}
