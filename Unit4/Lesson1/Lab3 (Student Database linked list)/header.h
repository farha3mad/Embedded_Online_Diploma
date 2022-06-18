#ifndef HEADER_T_
#define HEADER_T_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//effective data for students
struct Student_data
{
    unsigned int id;
    char name[40];
    float height;
};
//Student linked list
struct Student
{
    struct Student_data data;
    struct Student* next_student;
};

typedef enum
{
    No_error,
    Not_found,
    List_empty,
    list_full

}List_status;

List_status Add_new_student();
List_status Delete_student();
void Print_students();
void Delete_All();

List_status Get_Nth_student();
void Get_Length();
List_status Get_Nth_student_backward();
void Find_middle();
void reverse_list();
#endif

