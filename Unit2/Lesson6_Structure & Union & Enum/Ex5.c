#include <stdio.h>
#include <math.h>
#define pi 3.14159265358979323846
#define circle_area(r) pow(r,2)*pi 
int main()
{
	float r;
	printf("Enter the radius :");
	scanf("%f",&r);
	printf("Area= %.2f",circle_area(r));
}