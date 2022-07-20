/*
 *       File : main.c
 *      Author: Eng.Farha Emad Mohamed
 *  Created on: 14/7/2022
 *
 */
#include "student_system.h"
int main()
{
    //for I/O buffer problem
    setvbuf(stdout,NULL,_IONBF,0);
    setvbuf(stderr,NULL,_IONBF,0);

    FIFO_t fifo_students;
    unsigned int choice;

    if(fifo_init(&fifo_students,&buffer,Max_Number) == FIFO_NO_ERROR){
        printf("Database Successfully Initialized\n");
    }

    printf("===============Welcome to Student Management System===============\n");
    while(1)
    {
        printf("+++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("Choose one of the following options\n");
        printf("(1)Add new student manually\n");
        printf("(2)Add students from text file\n");
        printf("(3)Print all students\n");
        printf("(4)Find student by id\n");
        printf("(5)Find student by first name\n");
        printf("(6)Find students registered in a specific course\n");
        printf("(7)Total number of students\n");
        printf("(8)Delete student by id\n");
        printf("(9)Update student by id\n");
        printf("(10)Exit\n");
        printf("+++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("Enter option number:");
        scanf("%d",&choice);
        printf("+++++++++++++++++++++++++++++++++++++++++++++++\n");
        switch(choice)
        {
            case 1:
                if(add_student_manually(&fifo_students) == FIFO_NO_ERROR);
                break;
            case 2:
                if(add_student_from_file(&fifo_students)==FIFO_ERROR);
                break;
            case 3:
                if(print_all_students(&fifo_students)==FIFO_ERROR);
                break;
            case 4:
                if(find_student_by_id(&fifo_students)==FIFO_ERROR);
                break;
            case 5:
                if(find_student_by_first_name(&fifo_students)==FIFO_ERROR);
                break;
            case 6:
                if(find_students_registered_in_course(&fifo_students)==FIFO_ERROR);
                break;
            case 7:
                if(total_number_of_students(&fifo_students)==FIFO_NO_ERROR);
                break;
            case 8:
                if(delete_student_by_id(&fifo_students)==FIFO_NO_ERROR);
                break;
            case 9:
                if(update_student_by_id(&fifo_students)==FIFO_NO_ERROR);
                break;
            case 10:
                exit(1);
                break;
            default:
                break;
        }
    }
}
