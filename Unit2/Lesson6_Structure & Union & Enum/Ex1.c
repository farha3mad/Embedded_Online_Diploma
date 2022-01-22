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
struct student {
	char name[50];
	int roll;
	float marks;
};

void Display(struct student s);
int main(void) {
	setvbuf(stdout,NULL,_IONBF,0);
	struct student s ;
	printf("Enter information of a students : \n");
	printf("Enter name: ");
	gets(s.name);
	printf("Enter roll number: ");
	scanf("%d",&s.roll);
	printf("Enter marks: ");
	scanf("%f",&s.marks);
	Display(s);
	return 0;
}
void Display(struct student s)
{
	printf("\nDisplaying Information\n");
	printf("Name: %s\nRoll: %d\nMarks: %.2f\n",s.name,s.roll,s.marks);
}
