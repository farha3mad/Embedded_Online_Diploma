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

int isPrime (int x);
void printPrime(int a,int z);

int main(void) {
	setvbuf(stdout,NULL,_IONBF,0);
	int a,z;
	printf("Enter two numbers (interval): ");
	scanf("%d %d",&a,&z);
	printf("Prime numbers between %d and %d are: " ,a,z);
	printPrime(a,z);
	return 0;
}
//function to check if the number is prime or not
int isPrime (int x)
{
	int i;
	if(x<2)
		return 0;

	for(i=2 ; i<x ; i++)
	{
		if(x%i == 0)
			return 0;
	}
	return 1;
}
//function to print all prime numbers between two numbers
void printPrime(int a,int z)
{
	int i;
	for(i=a ; i<=z ;i++)
	{
		if(isPrime(i))
			printf("%d ",i);
	}

}
