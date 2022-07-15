/*
 *       File : student_system.h
 *      Author: Eng.Farha Emad Mohamed
 *  Created on: 14/7/2022
 *
 */

#ifndef _STUDENT_SYSTEM_H
#define _STUDENT_SYSTEM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Max_Number 50
#define Course_Number 5

//student information as an item
typedef struct{
    unsigned int ID;
    char First_Name[20];
    char Last_Name[20];
    float GPA;
    int Courses[Course_Number];
}student_data;

//Queue to control database buffer
typedef struct{
    unsigned int Length;
    unsigned int Count;
    student_data* Head;
    student_data* Base;
    student_data* Tail;
}FIFO_t;

//buffer to be the whole database
student_data buffer[Max_Number];

//Queue states
typedef enum{
    FIFO_NO_ERROR,
    FIFO_ERROR,
    FIFO_FULL,
    FIFO_EMPTY,
    FIFO_NULL,
    ID_NOT_UNIQE
}FIFO_STATE;

//APIs
/*initialize the queue*/
FIFO_STATE fifo_init(FIFO_t* fifo, student_data* buffer,unsigned int length);
/*inserting elements in queue*/
FIFO_STATE fifo_enqueue(FIFO_t* fifo,student_data item);
/*check if the id is unique*/
FIFO_STATE check_id(FIFO_t* fifo,unsigned int id);
/*add a student from user*/
FIFO_STATE add_student_manually(FIFO_t* fifo);
/*add a students from text file*/
FIFO_STATE add_student_from_file(FIFO_t* fifo);
/*showing all students in the queue*/
FIFO_STATE print_all_students(FIFO_t* fifo);
/*search for a student by id*/
FIFO_STATE find_student_by_id(FIFO_t* fifo);
/*search for a student by first name*/
FIFO_STATE find_student_by_first_name(FIFO_t* fifo);
/*find all students registered in a specific course*/
FIFO_STATE find_students_registered_in_course(FIFO_t* fifo);
/*find th number of students in the queue*/
FIFO_STATE total_number_of_students(FIFO_t* fifo);
/*deleting a student by id*/
FIFO_STATE delete_student_by_id(FIFO_t* fifo);
/*update a student data*/
FIFO_STATE update_student_by_id(FIFO_t* fifo);

#endif // _STUDENT_SYSTEM_H
