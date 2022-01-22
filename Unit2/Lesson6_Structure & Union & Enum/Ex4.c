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
struct student {
	char name[50];
	int roll;
	float marks;
};
void students_data_entry(struct student s[],int size);
void Display(struct student s[],int size);

int main(void)
{
	setvbuf(stdout,NULL,_IONBF,0);
	struct student s[10];
	students_data_entry(s,10);
	Display(s,10);
	return 0;
}
//function takes array of structures and its size.
//It takes the data of each structure from the user.
void students_data_entry(struct student s[],int size)
{
	int i;
	printf("Enter information of students: \n");
	for(i=0 ; i<size ; i++){
		s[i].roll=i+1;
		printf("for roll number %d\n",s[i].roll);
		printf("Enter name: ");
		scanf("%s",s[i].name);
		printf("Enter marks: ");
		scanf("%f",&s[i].marks);
	}
}
void Display(struct student s[],int size)
{
	int i;
	printf("\nDisplaying Information\n");
	for(i=0 ; i<size ; i++)
	{
		printf("Information of roll number %d:\n",s[i].roll);
		printf("Name: %s\nMarks: %.2f\n",s[i].name,s[i].marks);
	}

}
