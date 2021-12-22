/*
 ============================================================================
 Name        : Ex8.c
 Author      : Farha Emad
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char op;
	float x, y, result=0;
	printf("Enter operator either + or - or * or divide : ");
	fflush(stdout); fflush(stdin);
	scanf("%c",&op);
	printf("Enter two operands : ");
	fflush(stdout); fflush(stdin);
	scanf("%f %f",&x, &y);
	switch(op)
	{
	case '+':
		result = x + y;
		printf("%.2f %c %.2f = %.2f",x,op,y,result);
		break;
	case '-':
		result = x - y;
		printf("%.2f %c %.2f = %.2f",x,op,y,result);
		break;
	case '*':
		result = x * y;
		printf("%.2f %c %.2f = %.2f",x,op,y,result);
		break;
	case '/':
		if (y == 0)
		{
			printf("Division by zero!!");
		}
		else
		{
			result = x / y;
			printf("%.2f %c %.2f = %.2f",x,op,y,result);
		}
		break;
	default:
		printf("You Entered wrong operator!!");
		break;
	}
	return 0;
}
