/*
 ============================================================================
 Name        : q5.c
 Author      : Farha Emad
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
struct Employee
{
	char name [50];
	int id;
};
int main(void) {
	setvbuf(stdout,NULL,_IONBF,0);
	struct Employee e1 = {"Ahmed",101};             /*  ptr-->  | p1 | --> e1       */
	struct Employee e2 = {"Waleed",103};			/*			------              */
	struct Employee e3 = {"Rahma",105};				/* 			| p2 | --> e2       */
	struct Employee *p1 = &e1;						/*          ------              */
	struct Employee *p2 = &e2;						/*    		| p3 | --> e3       */
	struct Employee *p3 = &e3;
	struct Employee (*arr[3]) = {p1,p2,p3};  /*arr is an array of 3 elements of type pointer to structure*/
	struct Employee  (*(*ptr)[3]) = arr;     /*ptr is a pointer to array(arr)of 3 elements of type pointer to structure*/
	int i;
	for(i=0 ; i<3 ; i++)
	{
		printf("Employee name : %s \n",(*(*ptr+i))->name);
		printf("Employee id : %d \n",(*(*ptr+i))->id);
		printf("--------------------------------------\n");
	}
	return 0;
}
